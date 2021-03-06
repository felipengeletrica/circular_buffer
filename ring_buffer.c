#include "ring_buffer.h"

/**
 * @brief Init Ring Buffer
 * 
 * @param buffer 
 * @param size 
 * @return ring_handle_buf_t 
 */
ring_handle_buf_t ring_buf_init(type_data* buffer, size_t size)
{
    /* Allocation */
    ring_handle_buf_t ring_buf = malloc(sizeof(ring_buf_st));

	ring_buf->buffer = buffer;
	ring_buf->buffer_size = size;
	
	return ring_buf;
}

/**
 * @brief Push data
 * 
 * @param st_ring_buf 
 * @param data 
 * @return int 
 */
int ring_buf_push(ring_handle_buf_t st_ring_buf, type_data data)
{
    int next = 0;

    next = st_ring_buf->head + 1; 
    if (next > st_ring_buf->buffer_size)
        next = 0;

    st_ring_buf->buffer[st_ring_buf->head] = data;
    st_ring_buf->head = next;
    return 0;
}

/**
 * @brief Pop data 
 * 
 * @param st_ring_buf 
 * @param data 
 * @return int 
 */
int ring_buf_pop(ring_handle_buf_t st_ring_buf, type_data *data)
{
    int next = 0;
    size_t len_buffer = 0;

    next = st_ring_buf->tail + 1;
    if(next > st_ring_buf->buffer_size)
        next = 0;

    len_buffer = ring_buf_size(st_ring_buf);
    if (len_buffer == 0)
        return -1;

    *data = st_ring_buf->buffer[st_ring_buf->tail];
    st_ring_buf->tail = next;

    return 0;
}

/**
 * @brief flush buffer
 * 
 * @param st_ring_buf 
 * @return int 
 */
int ring_buf_flush(ring_handle_buf_t st_ring_buf)
{
    st_ring_buf->tail = 0;
    st_ring_buf->head = 0;
    return 0;
}

/**
 * @brief Free Buffer 
 * 
 * @param st_ring_buf 
 * @return int 
 */
int ring_buf_free(ring_handle_buf_t st_ring_buf)
{
    /* Free memory */
    free(st_ring_buf);
    return 0;
}

/**
 * @brief Read buffer size
 * 
 * @param st_ring_buf 
 * @return size_t 
 */
size_t ring_buf_size(ring_handle_buf_t st_ring_buf)
{
    size_t size = 0;

    if(st_ring_buf->head >= st_ring_buf->tail)
    {
        size = st_ring_buf->head - st_ring_buf->tail;
    }
    else
    {
        size = (st_ring_buf->buffer_size + st_ring_buf->head) - st_ring_buf->tail;
    }
    
    return size;
}

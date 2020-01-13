#include "ring_buffer.h"


ring_handle_buf_t ring_buf_init(uint8_t* buffer, size_t size)
{
    assert(buffer && size);

    ring_handle_buf_t ring_buf = malloc(sizeof(ring_buf_st));

    assert(ring_buf);

	ring_buf->buffer = buffer;
	ring_buf->buffer_size = size;
	
	return ring_buf;
}


int ring_buf_push(ring_handle_buf_t st_ring_buf, uint8_t data)
{
    int next;

    next = st_ring_buf->head + 1; 
    if (next >= st_ring_buf->buffer_size)
        next = 0;

    if (next == st_ring_buf->tail)
        return -1;

    st_ring_buf->buffer[st_ring_buf->head] = data;
    st_ring_buf->head = next;
    return 0;
}


int ring_buf_pop(ring_handle_buf_t st_ring_buf, uint8_t *data)
{
    int next;

    if (st_ring_buf->head == st_ring_buf->tail)
        return -1;

    next = st_ring_buf->tail + 1;
    if(next >= st_ring_buf->buffer_size)
        next = 0;

    *data = st_ring_buf->buffer[st_ring_buf->tail];
    st_ring_buf->tail = next;
    return 0;
}

#include "ring_buffer.h"

/**
 * @brief 
 * 
 * @param c 
 * @param data 
 * @return int 
 */
int circ_buf_push(circ_buf_st *c, uint8_t data)
{
    int next;

    next = c->head + 1; 
    if (next >= c->max_size)
        next = 0;

    if (next == c->tail)
        return -1;

    c->buffer[c->head] = data;
    c->head = next;
    return 0;
}


/**
 * @brief Pop BUffer
 * 
 * @param c 
 * @param data 
 * @return int 
 */
int circ_buf_pop(circ_buf_st *c, uint8_t *data)
{
    int next;

    if (c->head == c->tail)
        return -1;

    next = c->tail + 1;
    if(next >= c->max_size)
        next = 0;

    *data = c->buffer[c->tail];
    c->tail = next;
    return 0;
}

/**
 * @brief Clear ring buffer
 * 
 * @param c 
 * @return int 
 */
int circ_buf_clear(circ_buf_st *c)
{
    c->head = 0;
    c->tail = 0;

    return 0;
}
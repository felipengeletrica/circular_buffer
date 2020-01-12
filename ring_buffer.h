#ifndef RING_BUFFER_H
#define BUFFER_H

/* INCLUDES */
#include <stdint.h>

/* STRUCTS */
typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int max_size;
} circ_buf_st;

/* PROTOTYPES */
int circ_buf_push(circ_buf_st *c, uint8_t data);
int circ_buf_pop(circ_buf_st *c, uint8_t *data);
#endif /* RING_BUFFER_H */
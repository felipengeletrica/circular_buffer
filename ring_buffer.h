#ifndef RING_BUFFER_H
#define BUFFER_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DEFINES */
/* Flexible buffer data type */
typedef uint_fast16_t type_data;

/* STRUCTS */
typedef struct {
    type_data * buffer;
    size_t head;
    size_t tail;
    size_t buffer_size;
} ring_buf_st;

/* VARIABLES */
typedef ring_buf_st* ring_handle_buf_t;

/* PROTOTYPES */
ring_handle_buf_t ring_buf_init(type_data* buffer, size_t size);
int ring_buf_push(ring_handle_buf_t st_ring_buf, type_data data);
int ring_buf_pop(ring_handle_buf_t st_ring_buf, type_data *data);
int ring_buf_flush(ring_handle_buf_t st_ring_buf);
int ring_buf_free(ring_handle_buf_t st_ring_buf);
size_t ring_buf_size(ring_handle_buf_t st_ring_buf);

#ifdef __cplusplus
}
#endif
#endif /* RING_BUFFER_H */
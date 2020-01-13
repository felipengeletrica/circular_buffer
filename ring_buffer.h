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

/* STRUCTS */
typedef struct {
    uint8_t * buffer;
    size_t head;
    size_t tail;
    size_t buffer_size;
} ring_buf_st;

// Handle type, the way users interact with the API
typedef ring_buf_st* ring_handle_buf_t;

/* PROTOTYPES */
ring_handle_buf_t ring_buf_init(uint8_t* buffer, size_t size);
int ring_buf_push(ring_handle_buf_t st_ring_buf, uint8_t data);
int ring_buf_pop(ring_handle_buf_t st_ring_buf, uint8_t *data);
int ring_buf_reset(ring_handle_buf_t st_ring_buf);
int ring_buf_free(ring_handle_buf_t st_ring_buf);

#ifdef __cplusplus
}
#endif
#endif /* RING_BUFFER_H */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ring_buffer.h"

#define MAX_SIZE_CIRCULAR_BUFFER 500

#define CIRC_BBUF_DEF(x,y)                \
    uint8_t x##_data_space[y];            \
    circ_buf_st x = {                     \
        .buffer = x##_data_space,         \
        .head = 0,                        \
        .tail = 0,                        \
        .max_size = y                     \
    }


circ_buf_st st_circ_buf;


 CIRC_BBUF_DEF(st_circ_buf, MAX_SIZE_CIRCULAR_BUFFER);


int main()
{
    printf("Tests Circular buffer\n\r");

    uint cont = 0;
    uint8_t out_data = 0;

    for(cont = 0; cont < MAX_SIZE_CIRCULAR_BUFFER - 1; cont++)
    {
        if (circ_buf_push(&st_circ_buf, 0xff))
        {
            printf("Out of space in CB\n");
            return -1;
        }
    }


    for(cont = 0; cont < MAX_SIZE_CIRCULAR_BUFFER; cont++)
    {
        if (circ_buf_pop(&st_circ_buf, &out_data))
        {
            printf("CB is empty\n");
            return -1;
        }

        printf("INDEX: %d DATA: %d\n\r", cont, out_data);
    }
  
    return (0);
}

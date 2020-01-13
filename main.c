#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ring_buffer.h"

#define BUFFER_SIZE 500


int main()
{
    int cont = 0;
    type_data data = 0;
    printf("Tests Circular buffer\n\r");

    type_data * buffer  = malloc(BUFFER_SIZE * sizeof(type_data));
    ring_handle_buf_t cbuf = ring_buf_init(buffer, BUFFER_SIZE);

    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        ring_buf_push(cbuf, cont & 0xff);
        printf("cont: %d Value: %f \n\r", cont, cont & 0xff);
    }


    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        ring_buf_pop(cbuf, &data);
        printf("cont: %d Values: %f \n\r", cont, data);
    }

    return 0;
}

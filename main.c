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

    for(cont = 0; cont < 600; cont++)
    {
        ring_buf_push(cbuf, (type_data ) (cont));
        printf("cont: %d Value: %d \n\r", cont, (type_data ) (cont));
    }


    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        ring_buf_pop(cbuf, &data);
        printf("cont: %d Values: %d \n\r", cont, data);
    }

    return 0;
}

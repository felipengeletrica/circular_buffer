#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ring_buffer.h"

#define BUFFER_SIZE 500


int main()
{
    int cont = 0;
    void *ptr; // Declaring a void pointer

    uint32_t data = 0;

    printf("Tests Circular buffer\n\r");

    uint32_t * buffer  = malloc(BUFFER_SIZE * sizeof(data));

    ptr=&buffer; // Assigning address of integer to void pointer.

    ring_handle_buf_t cbuf = ring_buf_init(ptr, BUFFER_SIZE);

    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        ring_buf_push(cbuf, (uint32_t) (cont));
        printf("cont: %d Value: %d \n\r", cont, (uint32_t ) (cont));
    }


    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        ring_buf_pop(cbuf, &data);
        printf("cont: %d Values: %d \n\r", cont, data);
    }

    return 0;
}

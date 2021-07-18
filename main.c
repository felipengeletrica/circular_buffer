#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ring_buffer.h"

#define BUFFER_SIZE 500


int main()
{
    int cont = 0;

    printf("Tests Circular buffer\n\r");

    ring_handle_buf_t cbuf = ring_buf_init(BUFFER_SIZE);

    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        int * i = malloc(sizeof(int));
        *i = cont;
        ring_buf_push(cbuf, i);
        printf("push cont: %d Value: %d \n\r", cont, (uint32_t ) (cont));
    }


    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        int *i;
        ring_buf_pop(cbuf, (void*) &i);
        printf("pop cont: %d Values: %d \n\r", cont, *i);
    }

    return 0;
}

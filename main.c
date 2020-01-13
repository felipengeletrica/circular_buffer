#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ring_buffer.h"

#define BUFFER_SIZE 500


int main()
{
    int cont = 0;
    printf("Tests Circular buffer\n\r");

    uint8_t * buffer  = malloc(BUFFER_SIZE * sizeof(uint8_t));
    ring_handle_buf_t cbuf = ring_buf_init(buffer, BUFFER_SIZE);

    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        ring_buf_push(cbuf, 0xff);
        printf("cont: %d", cont);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ring_buffer.h"

#define BUFFER_SIZE 500

/* STRUCT DATA */
typedef struct {
  int status;
} st_values;


int main()
{
    int cont = 0;
    st_values values_st [BUFFER_SIZE] = { 0 };
    ring_handle_buf_t cbuf = ring_buf_init(BUFFER_SIZE);

    printf("Tests Circular buffer\n\r");

    /* Push data in buffer */
    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        values_st[cont].status = cont;
        ring_buf_push(cbuf, (void *) &values_st[cont]);
        printf("push cont: %d Value: %d \n\r", cont, (uint32_t ) (cont));
    }

    /* Pop data */
    for(cont = 0; cont < BUFFER_SIZE; cont++)
    {
        st_values *st_get_values;
        ring_buf_pop(cbuf, (void*) &st_get_values);
        printf("pop cont: %d Values: %d \n\r", cont, st_get_values->status);
    }

    return 0;
}

#include "utility_header.h"
#include <stdio.h>

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

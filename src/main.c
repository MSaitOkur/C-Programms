#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utility.h"
#include "mystring.h"

#define SIZE 100

char *mystrcat(char *dest, const char *source)
{
    
}


int main(void)
{
    char str[SIZE];
    fprintf(stdout, "Enter a sentence: ");
    sgets(str, stdin);

    puts(mystrrev(str));
}
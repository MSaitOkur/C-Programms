#include "utility_header.h"
#include <stdio.h>

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int isleap(int year)
{
    return !(year % 4) && (year % 100 || !(year % 400)) ? 1 : 0;
}

size_t sum_digit(size_t num)
{
    size_t sum = num % 10;

    while(num /= 10)
        sum += num % 10;

    return sum;
}

int num_digits(int number)
{
    if(number == 0)
        return 1;

    int ndigits = 0;
    while(number != 0)
        ++ndigits, number /= 10;
    
    return ndigits;
}

int rev_digits(int number)
{
    int rev = 0;

    while(number)
    {
        rev *= 10;
        rev += number % 10;
        number /= 10;
    }
    return rev;
}

int string_to_number(char *str, int base)
{
    int number = 0;

    if (base != 16)
    {
        for (size_t i = 0; str[i] != '\0'; ++i)
        {
            number *= base;
            number += str[i] - '0';
        }
    }
    else
    {
        for (size_t i = 0; str[i] != '\0'; ++i)
        {
            if ( str[i] >= '0' && str[i] <= '9')
            {
                number *= base;
                number += str[i] - '0';
            }
            else if ( str[i] >= 'a' && str[i] <= 'f')
            {
                number *= base;
                number += str[i] - 'a' + 10;
            }
            else if ( str[i] >= 'A' && str[i] <= 'F')
            {
                number *= base;
                number += str[i] - 'A' + 10;
            }
        }
    }

    return number;
}
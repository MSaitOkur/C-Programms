#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <stddef.h>

void clear_input_buffer(void);
int isleap(int year);
size_t sum_digit(size_t num);
int num_digits(int number);
int rev_digits(int number);
int string_to_number(char *str, int base);






#endif // UTILITY_HEADER

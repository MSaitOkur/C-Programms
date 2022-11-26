#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#undef RANDOM_VALUE_MAX
#define RANDOM_VALUE_MAX 100

#define randomize() (srand((size_t)time(NULL)))

void swap_int(int *i1, int *i2);

void set_array_random_int(int *ar, size_t ar_size);
void display_array_int(int *ar, size_t ar_size);
int *bubble_sort_int(int *arr, size_t size);
int *bubble_sort_int_odds_evens(int *arr, size_t size);

size_t bin_search_int(int *arr, size_t size, int sval);

#endif // UTILITY_HEADER

#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap_int(int *i1, int *i2)
{
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}

void set_array_random_int(int *ar, size_t ar_size)
{
    randomize();

    for (size_t i = 0; i < ar_size; ++i)
        ar[i] = rand() % RANDOM_VALUE_MAX;
}

void display_array_int(int *ar, size_t ar_size)
{
    putchar('\n');
    for (size_t i = 0; i < ar_size; ++i)
    {
        if (i && i % 15 == 0)
            putchar('\n');
        printf("%3d ", ar[i]);
    }
    putchar('\n');
}

int *bubble_sort_int(int *arr, size_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
        for (size_t j = 0; j < size - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
                swap_int(arr + j, arr + j + 1);

    return arr;
}

int *bubble_sort_int_odds_evens(int *arr, size_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
        for (size_t j = 0; j < size - 1 - i; ++j)
            if ((arr[j] % 2 == 0 && arr[j + 1] % 2) ||
                (arr[j] % 2 == arr[j + 1] % 2 && arr[j] > arr[j + 1]))
                swap_int(arr + j, arr + j + 1);

    return arr;
}

size_t bin_search_int(int *arr, size_t size, int sval)
{
    size_t idx_first = 0;
    size_t idx_last = size - 1;
    size_t idx_mid;

    while (idx_first <= idx_last)
    {
        idx_mid = (idx_first + idx_last) / 2;
        if (arr[idx_mid] == sval)
            return idx_mid;
        else if (arr[idx_mid] < sval)
            idx_first = idx_mid + 1;
        else
            idx_last = idx_mid - 1;
    }

    return size;
}
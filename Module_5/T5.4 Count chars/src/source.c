#include <stdio.h>

/**
 * \brief Counts the number of occurrences of characters in an array
 *
 * \param array A zero (0) terminated string that is composed some number of characters
 * \param counts An int array of 256 elements that contains number of character occurrences.
 */

void count_chars(const char *array, unsigned int *counts)
{
    while (*array != 0) {
        counts[(unsigned char)*array]++;
        array++;
    }
 }

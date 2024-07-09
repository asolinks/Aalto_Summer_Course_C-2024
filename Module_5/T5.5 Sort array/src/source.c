
#include "source.h"
#include <stdlib.h>

/**
 * \brief Compares two values pointed by the pointers
 *
 * \param p1 The address of the first value
 * \param p2 The address of the second value
 * \returns 0 The element pointed to by p1 is equivalent to the element pointed to by p2
 * \returns <0 The element pointed to by p1 goes before the element pointed to by p2
 * \returns >0 The element pointed to by p1 goes after the element pointed to by p2
 */
int compare_ascending(const void *p1, const void *p2)
{
    const int *int_p1 = (const int *)p1;
    const int *int_p2 = (const int *)p2;
    return (*int_p1 - *int_p2);}

/**
 * \brief Sorts an integer array in ascending order
 *
 * \param array The array to be sorted
 * \param size The number of elements in the array
 */
void sort(int *array, int size)
{
    qsort(array, size, sizeof(int), compare_ascending);
    
}


#include "source.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * \brief Creates a dynamically allocated array and reads the specified number of
 *        integers from the standard input stream.
 *
 * \param n The number of integers to be read
 * \return A pointer to the allocated and filled array
 */
int *create_dyn_array(unsigned int n)
{
       int *arr = (int *)malloc(n * sizeof(int));  
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    
    
    for (unsigned int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error reading integer number %u.\n", 				i+1);
            free(arr);  
            return NULL;
        }
    }
    
    return arr;  
}

/**
 * \brief Appends a new element to the existing and dynamically allocated array
 *
 * \param arr The dynamically allocated array of num elements
 * \param num The number of elements in arr
 * \param newval The value of the new element that will be appended
 * \return A pointer to the resized array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    arr = (int *)realloc(arr, (num + 1) * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed.\n");
        return NULL;
    }
    
    
    arr[num] = newval;
    
    return arr;  
}

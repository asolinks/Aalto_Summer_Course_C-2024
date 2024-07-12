#include "source.h"
#include <stdio.h>


/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    while (*s != '?' && *s != '\0') {
        putchar(*s);
        s++;
    }
}
/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    unsigned int len = 0;
    while (*s != '?' && *s != '\0') {
        len++;
        s++;
    }
    return len;
}
/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */

int qstr_cat(char *dst, const char *src) {
    
    char *dst_end = dst;
    while (*dst_end != '?' && *dst_end != '\0') {
        dst_end++;
    }
    
    
    while (*src != '?' && *src != '\0') {
        *dst_end = *src;
        dst_end++;
        src++;
    }
    
    
    *dst_end = '?';
    dst_end++;
    *dst_end = '\0'; 
    
    
    return dst_end - dst - 1;
}
#include "source.h"
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{
    
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    
    char *new_dest = (char *)malloc(dest_len + src_len + 1); 
    if (new_dest == NULL) {
        return NULL; 
    }

    
    strcpy(new_dest, dest);

    
    strcat(new_dest, src);

    
    free(dest);

    
    return new_dest;
}

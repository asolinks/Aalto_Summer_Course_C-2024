#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string(const char *str)
{
   unsigned int len = strlen(str);
    char *newstr = malloc(len + 1); 
    if (newstr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    
    for (unsigned int i = 0; i < len; i++)
    {
        newstr[i] = str[len - i - 1]; 
    }
    newstr[len] = '\0'; 
    
    return newstr;}

int main(void)
{    char *rev;
    
    
    rev = reverse_string("Hi there");
    if (rev != NULL) {
        printf("%s\n", rev);
        free(rev); 
    }
    
    
    rev = reverse_string("Hello there");
    if (rev != NULL) {
        printf("%s\n", rev);
        free(rev); 
    }
    
    return 0;
}

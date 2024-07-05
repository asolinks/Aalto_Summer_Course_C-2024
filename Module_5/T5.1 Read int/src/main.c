#include <stdio.h>

// declare and define the function here
int* read_int(int* number) {
    if (number == NULL) {
        return NULL; 
    }

    if (scanf("%d", number) == 1) {
        return number; 
    } else {
        return NULL;
    }
}

int main(void)
{
    int a;
    int* ret = read_int(&a);
    printf("return value: %p\n", (void*)ret);
    if (ret != NULL)
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");


    return 0;
}

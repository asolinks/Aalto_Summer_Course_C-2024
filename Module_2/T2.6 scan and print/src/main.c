#include <stdio.h>

int main(void)
{
    int a;
    float f;
    
    int ret_a = scanf("%d %f", &a, &f);
    
 
    printf("Captured %d\n", ret_a);
    
    printf("Integer is 0x%08x\n", a);
    
    printf("Floating-point number is %8.3f\n", f);
    
    return 0;
}
# include <stdio.h>
# include "source.h"

double fracsum(int x, int y, int a, int b) {
    double frac1 = (double)x / y;
    double frac2 = (double)a / b;
    return frac1 + frac2;
}


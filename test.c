#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double *p1;
    p1 = (double*)malloc(sizeof(double));
    p1[0] = 23.92;
    printf("%lf\n", p1[0]);
    return 0;
}
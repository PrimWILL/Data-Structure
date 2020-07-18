#include <stdio.h>

double slow_power(double x, int n)
{
    double result = 1.0;

    for(int i = 0; i < n; i++){
        result = result * x;
    }
    return result;
}

int main(void){
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    printf("%.0f", slow_power(x, n));
    return 0;
}
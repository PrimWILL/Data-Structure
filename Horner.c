#include <stdio.h>

double horner_func(double x, unsigned int n, double *arr);
double recur_horner_func(double x, unsigned int n, unsigned int cnt, double* arr);

void main(void)
{
    double arr[] = {1, 2, 3, 4, 5};
    double result;
    unsigned int n;

    n = sizeof(arr)/sizeof(double);

    result = horner_func(3, n, arr);
    printf("Result = %.3f\n", result);
    
    result = recur_horner_func(3, n, 0, arr);
    printf("Result = %.3f\n", result);
}

double horner_func(double x, unsigned int n, double* arr)
{
    double result = 0.0;
    unsigned int i;

    for (i = 0; i < n; i++) result = result * x + arr[n - 1 - i];
    return result;
}

double recur_horner_func(double x, unsigned int n, unsigned int cnt, double* arr)
{
    if (cnt >= n - 1) return arr[cnt];
    else return recur_horner_func(x, n, cnt + 1, arr) * x + arr[cnt];
}
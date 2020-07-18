#include <stdio.h>

double Ackermann(double m, double n)
{
    if (m == 0) return n + 1;
    else if (n == 0) return Ackermann(m - 1, 1);
    else return Ackermann(m - 1, Ackermann(m, n -1));
}

int main(void)
{
    double m, n;
    scanf("%lf %lf", &m, &n);

    printf("%lf\n", Ackermann(m, n));
    return 0;
}
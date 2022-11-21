#include <stdio.h>

#define N 4

typedef struct polynom
{
    int degree;
    double coef[N+1];
}
polynom;

double evalHorner (polynom* poly, double x)
{
    double sum = 0.0;

    for (int i = 0; i <= poly->degree; i++)
    {
        sum = sum * x + poly->coef[i];
    }

    return sum;
}

int main(void)
{
    polynom mypoly = {4, {3.0, 2.0, -1.0, 1.0, 4.0}};
    double x = 2.0;

    printf("value of polynome in %f is %f\n", x, evalHorner(&mypoly, x));
    return 0;
}
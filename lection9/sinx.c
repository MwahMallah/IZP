#include <stdio.h>
#include <stdlib.h>


float fabs(float x)
{
    if (x < 0)
    {
        return -x;
    }

    return x;
}

float sinsin(float x, float precision)
{
    float t = x;
    float sum = x;
    int n = 1;

    while (fabs(t) >= precision * fabs(sum))
    {
        n += 2;
        t *= -x*x/(n*(n-1));
        sum += t;
    }

    return sum;
}

int main(void)
{
    float x = 3.1415926;
    float precision = 1;

    printf("sin(%f) = %f", x, sinsin(x, precision));
}
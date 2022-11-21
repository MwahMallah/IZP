#include <stdio.h>
#include <math.h>

#define precision 0.01
#define N 4

typedef struct 
{
    int degree;
    int coefficients[N+1];
}
polynom;

void define_polynomial(polynom* poly)
{
    poly->degree = N;
    for (int i = 0; i < poly->degree + 1; i++)
    {
        printf("enter %d's coefficient\n", i+1);
        scanf("%d", &poly->coefficients[i]);
    }
}


float function(polynom* poly, float x)
{
    float sum = 0.0;

    for (int i = 0; i < poly->degree + 1; i++)
    {
        sum = sum*x + poly->coefficients[i];
    }

    return sum;
}

float root(polynom* poly, float x_0, float x_1)
{
    float middle = (x_0 + x_1) / 2.0;

    while (fabs( function(poly, middle) ) > precision)
    {
        if (function(poly, middle) * function(poly, x_0) < 0)
        {
            x_1 = middle;
        }

        else if (function(poly, middle) * function(poly, x_1) < 0)
        {
            x_0 = middle;
        }

        middle = (x_0 + x_1) / 2.0;
    }

    return middle;
}

int main(void)
{
    polynom poly;
    define_polynomial(&poly);

    float boundary_0, boundary_1;
    do 
    {
        printf("Input first boundary: ");
        scanf("%f", &boundary_0);
    
        printf("Input second boundary: ");
        scanf("%f", &boundary_1);
    }
    while (function(&poly, boundary_0) * function(&poly, boundary_1) > 0);

    float function_root = root(&poly, boundary_0, boundary_1);

    printf("Function's root is %f\n", function_root);
}
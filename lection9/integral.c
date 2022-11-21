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

float find_integral(polynom* poly, float x_0, float x_1)
{
    float sum = 0.0;
    float step = (x_1 - x_0) / 1000;

    for (float i = x_0; i < x_1 - (step/2); i += step)
    {
        sum += function(poly, i);
    }

    sum*= step;

    return sum;
}

int main(void)
{
    polynom poly;
    define_polynomial(&poly);

    float boundary_0, boundary_1;
    printf("Input first boundary: ");
    scanf("%f", &boundary_0);
    
    printf("Input second boundary: ");
    scanf("%f", &boundary_1);
    

    float integral = find_integral(&poly, boundary_0, boundary_1);

    printf("Function's integral between [%.1f, %.1f] is %f\n", boundary_0, boundary_1, integral);
}
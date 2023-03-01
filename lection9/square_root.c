#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    float x;
    printf("input number: ");
    scanf("%f", &x);

    float precision = 0.00000001;
    float y = 1.0;
    float square_root = (x/y + y) / 2.0;

    int i = 1;

    while (fabs(square_root - y) >= precision)
    {
        printf("%d.", i);
        y = square_root;
        square_root = (x/y + y) / 2.0;
        printf(" %f\n", fabs(square_root - y));
        i++;
    }

    printf("%f\n", square_root);
}
#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;
    printf("input number: ");
    scanf("%f", &x);

    float member = 1;
    float summa = member;
    float i = 0;
    float precision = 0.001;

    while(fabs(member) >= precision)
    {
        i++;
        member *= x / i;
        summa += member;
    }

    printf("%f\n", summa);
}
#include <stdio.h>

void convertion(int number, int base)
{
    if (number < base)
    {
        printf("%d", number);
        return ;
    }

    convertion(number/base, base);
    convertion(number % base, base);
}

int main(void)
{
    int number, base;
    printf("Input number: ");
    scanf("%d", &number);

    printf("Input base from 1 to 16: ");
    scanf("%d", &base);

    convertion(number, base);
}
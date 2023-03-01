#include <stdio.h>

int my_abs(int x);

int main(void)
{
    int number;
    printf("input integer number: ");
    scanf("%i", &number);
    number = my_abs(number);
    printf("%i", number);
}


int my_abs(int x)
{
    return x < 0 ? -x : x;
}
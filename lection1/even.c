#include <stdio.h>

int main(void)
{
    int num;

    printf("Input number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("number is even\n");
    }

    else if (num % 3 == 0)
    {
        printf("numer is not even");
    }

    else
    {
        printf("number is uneven\n");
    }
}
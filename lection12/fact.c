#include <stdio.h>

long int fact(long number)
{
    if (number == 0)
    {
        return 1L;
    }

    return number * fact(number - 1);
}

int main(void)
{
    printf("Enter number: ");
    long number;
    scanf("%li", &number);

    printf("%li is a factorial of %d\n", fact(number), number);
}
#include <stdio.h>

int main(void)
{
    int year;

    printf("Input year ");
    scanf("%d", &year);

    if (year % 4 == 0)
    {
        if (year % 100 == 0 && year % 400 != 0)
        {
            printf("not a leap year\n");
        }

        else
        {
            printf("leap year\n");
        }
    }

    else
    {
        printf("not a leap year\n");
    }

    return 0;
}

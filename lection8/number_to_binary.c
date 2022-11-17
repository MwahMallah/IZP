#include <stdio.h>

int main(void)
{
    int N = 25;
    char binary_N[100];
    int remainder;
    int digit = 0;

    while (N > 0)    
    {
        remainder = N % 2;
        N = N / 2;

        if (remainder == 0)
        {
            binary_N[digit] = '0';
        }

        else if (remainder == 1)
        {
            binary_N[digit] = '1';
        }
        digit++;
    }

    printf("%s\n", binary_N);
    

    int max = 0;
    int checker;
    int count = -1000;

    /*
    while (binary_N != 0)
    {
        checker = binary_N % 10;
        binary_N = binary_N / 10;

        if (checker == 1)
        {
            if (count > max)
            {
                max = count;
            }
            count = 0;
            continue;
        }

        count++;
    }

    printf("%d\n", max);
    */

}
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int x = 10;
    int div = 1;

    while (x / div >= 10)
    {
        div *= 10;
    }

    x = (x % div) / 10;

    printf("%d\n", div);
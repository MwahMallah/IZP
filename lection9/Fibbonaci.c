#include <stdio.h>


int fib(int idx)
{
    if (idx <= 0)
    {
        return 0;
    }

    if (idx == 1)
    {
        return 1;
    }

    int summa = fib(idx - 1) + fib(idx-2);

    return summa;
}

int main(void)
{
    int idx;
    printf("Input number: ");
    scanf("%d", &idx);
    int fib_num = fib(idx);
    printf("fibonaci cislo: %d\n", fib_num);
}

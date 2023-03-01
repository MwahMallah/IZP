#include <stdio.h>
#include <stdbool.h>
#define N 10000


int main(void)
{
    bool a[N];

    for (int i = 2; i < N; i++)
    {
        a[i] = true;
    }

    for (int i = 2; i < 100; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                a[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        if (a[i])
        {
            printf("%d, ", i);
        }
    }
    return 0;
}
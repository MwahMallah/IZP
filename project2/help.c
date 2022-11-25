#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h> // sqrtf
#include <limits.h> // INT_MAX

int main(void)
{
    const int arr_size = 8;
    int arr[] = {1, 5, 11, 53, 28, 2, 4, 48};

    int c1, c2;
    int max = 0;

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = i+1; j < arr_size; j++)
        {
            if (arr[i] * arr[j] > max)
            {
                c1 = i;
                c2 = j;
                max = arr[i] * arr[j];
            }
        }
    }

    printf("first index: %d\nsecond index: %d\n", c1, c2);
}
#include <stdio.h>

int IsSet(int*, int);

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8};
    int length = 8;

    if (IsSet(array, length) == 0)
    {
        printf("Array is set\n");
    }

    else 
    {
        printf("Array is not set\n");
    }

    return 0;
}

int IsSet(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (array[i] == array[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
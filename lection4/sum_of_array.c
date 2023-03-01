#include <stdio.h>

int getSum(int*, int);

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8};
    int length = 8;

    int sum;

    sum = getSum(array, length);
    printf("%i", sum);
    return 0;
}

int getSum(int massiv[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += massiv[i];
    }
    return sum;
}
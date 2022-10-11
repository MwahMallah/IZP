#include <stdio.h>

void IsInSet(int*, int);

int main(void)
{
    int arr2[] = {1,2,3,4,5};
    int n = 5;
    IsInSet(arr2, n);
}

void IsInSet(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", arr[i]);
    }
}
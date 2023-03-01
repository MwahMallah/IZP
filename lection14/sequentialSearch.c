#include <stdio.h>
#include <stdbool.h>

int sequenceSearch(int* arr, int num)
{
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    arr[arrLength] = num;
    int i = 0;
    bool found = false;

    while (found != true)
    {
        if (arr[i] == num)
        {
            found = true;
        }

        i++;
    }

    if (i == arrLength)
    {
        return -1;
    }

    return i;
}

int main(void)
{
    int arr[] = {1 , 2, 5, 13, 8};
    
    int place = sequenceSearch(arr, 8);
    
    printf("place is %d\n", place);
}
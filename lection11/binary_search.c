#include <stdio.h>

#define SIZE 10

int linearSearch(int array[SIZE], int number)
{


    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] == number)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int array[], int number)
{
    int right = SIZE - 1;    
    int left = 0;

    int middle = (right + left) / 2;

    while (right - left > 0)
    {
        if (array[middle] == number)
        {
            return middle;
        }

        if (array[middle] > number)
        {
            right = middle;
            middle = (right + left) / 2;
        }

        else if (array[middle] < number)
        {
            left = middle;
            middle = (right + left) / 2;
        }
    }
}



int main(void)
{
    int number = 110;
    int array[SIZE] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170};

    printf("size is %d\n", sizeof(array)/sizeof(array[0]));


    int idx = linearSearch(array, number);
    printf("number is at index %d\n", idx);

    idx = binarySearch(array, number);
    printf("number is at index %d\n", idx);
}
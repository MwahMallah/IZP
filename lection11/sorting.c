#include <stdio.h>

#define SIZE 7

void selectionSort(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        int min_idx = i;
        int min = array[i];

        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                min_idx = j;
            }
        }

        array[min_idx] = array[i];
        array[i] = min;
    }
    return ;
}

void bubbleSort(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = SIZE - 1; j > i; j--)
        {
            if (array[j] < array[j-1])
            {
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp; 
            }
        }
    }
    return ;
}

int main(void)
{
    int array[] = {11, 3, 27, 8, 50, 22, 12};
    
    printf("array = [%d", array[0]);
    for (int i = 1; i < SIZE; i++)
    {
        printf(", %d", array[i]);
    }
    printf("]");

    selectionSort(array);

    printf("\n");

    printf("Sorted by selection sort = [%d", array[0]);
    for (int i = 1; i < SIZE; i++)
    {
        printf(", %d", array[i]);
    }
    printf("]");
    printf("\n\n");



    int array2[] = {11, 27, 8, 50, 22, 3, 12};
    
    printf("array2 = [%d", array2[0]);
    for (int i = 1; i < SIZE; i++)
    {
        printf(", %d", array2[i]);
    }
    printf("]");

    bubbleSort(array2);

    printf("\n");

    printf("Sorted by bubble sort = [%d", array2[0]);
    for (int i = 1; i < SIZE; i++)
    {
        printf(", %d", array2[i]);
    }
    printf("]");
}
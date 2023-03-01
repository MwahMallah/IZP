#include <stdio.h>

void multiplyAllByConstant(int array[], int arr_size, int constanta)
{
    for (int i = 0; i < arr_size; i++)
    {
        array[i] *= constanta;
    }
}

void insertAt(int array[], unsigned int arraySize, int what, int at)
{
    for (int i = arraySize; i > 0; i--)
    {
        if (i < at)
        {
            ;
        }

        else if (i == at)
        {
            array[i] = what;
        }
        else
        {
            array[i] = array[i-1];
        }
    }
}


int main(int argc, char* argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};

    unsigned int arr_size = 5;



    insertAt(arr, arr_size, 6,3);

    printf("array is now = [");
    for (int i = 0; i < arr_size - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d]\n", arr[arr_size-1]);
}
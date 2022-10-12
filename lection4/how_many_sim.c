#include <stdio.h>

int check_array(int*, int*, int);

int main(void)
{
    int array_1[] = {1,2,3,6};
    int array_2[] = {3,4,5,6};
    int length = 4;

    int sim;

    sim = check_array(array_1, array_2, length);
    printf("%i", sim);
    return 0;
}

int check_array(int array1[], int array2[], int length)
{
    int simillar = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (array1[i] == array2[j])
            {
                simillar++;
            }
        }
    }

    return simillar;
}
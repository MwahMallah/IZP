#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numsSize = 4; 
    int nums[] = {2,7,11,15};
    int target = 9;
    int* arr = malloc(sizeof(int) * 2);
    
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = nums[i];
                arr[1] = nums[j];
                printf("%i - arr[0], %i - arr[1]\n", arr[0], arr[1]);
            }
        }
    }    
    
    return 0;
}
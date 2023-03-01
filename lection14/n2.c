#include <stdio.h>

int main(void)
{
    int arr[11] = {7, 6, 4, [7]=10, 9, 8, 5};
    printf("%d\n", arr[8]);
}
#include <stdio.h>

int main(void)
{
    int hotovost[4][3];
    hotovost[2][1] = 7;
    int* p = *hotovost;
    printf("%i\n", *(p+(2*3)+1));
}
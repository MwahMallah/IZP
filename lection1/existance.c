#include <stdio.h>

int main(void)
{
    int interval_start = 0, interval_end = 10;
    int num;

    printf("Input number: ");
    scanf("%d", &num);

    if (num >= interval_start && num <= interval_end)
    {
        printf("%d is in the inteval [%d , %d]\n", num, interval_start, interval_end+1);
    }

    if (num < interval_start || num > interval_end)
    {
        printf("%d is not in the inteval [%d , %d]\n", num, interval_start, interval_end);
    }
}

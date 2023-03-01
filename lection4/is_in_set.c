#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char i[10];
    printf("input: \n");
    fgets(i, 10, stdin);
    printf("%s", i);
}


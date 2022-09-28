#include <stdio.h>

int main(void)
{
    int a,b,c;

    printf("input three numbers a,b,c\n");

    scanf("%i%i%i", &a,&b,&c);

    int discr = b*b - 4 * a * c;

    printf("%i", discr);
}
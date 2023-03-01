#include <stdio.h>

int main(void)
{
    char* name = "config.txt";
    FILE* file = fopen(name, "r");

    int c;

    while ((c = getc(file)) != EOF)
        printf("%c", c);

    fclose(file);
}
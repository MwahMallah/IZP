#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void swap(char* a, char* b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    char* text = malloc(6);
    char text2[] = "Hello";

    strcpy(text, text2);

    swap(&(text[0]), &(text[1]));

    printf("%s", text);
}
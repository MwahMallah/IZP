#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* a, char* b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    char* text = malloc(10);
    scanf("%s", text);

    printf("Old string: %s\n", text);

    int text_length = strlen(text);

    for (int i = 0; i < text_length / 2; i++)
    {
        swap(&text[i], &text[text_length - i - 1]);
    }

    printf("New string: %s\n", text);
}
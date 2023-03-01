#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define string1_len 10

int main(void)
{
    char* string1 = malloc(sizeof(char) * string1_len);
    char* string2 = "hello world abs";

    for (int i = 0; i < string1_len; i++)
    {
        string1[i] = string2[i];
    }

    string1[string1_len] = '\0';

    string1 = realloc(string1, string1_len - 5);

    printf("%s", string1);
    free(string1);
}
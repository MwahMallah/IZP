#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat(char*, char*);

int main(void)
{
    char* string1 = malloc(sizeof(char));
    char* string2 = malloc(sizeof(char));

    printf("Input first string: ");
    scanf("%s", string1);

    printf("Input second string: ");
    scanf("%s", string2);

    cat(string1, string2);

    printf("%s", string1);
}

void cat(char* string1, char* string2)
{
    int len_string1 = strlen(string1);
    int len_string2 = strlen(string2);
    string1 = realloc(string1, len_string1 + len_string2 + 1);

    string1[len_string1] = ' ';

    int i = 0;
    for (i = 0; string2[i] != '\0'; i++)
    {
        string1[i + len_string1 + 1] = string2[i]; 
    }

    string1[i+len_string1+1] = '\0';
}
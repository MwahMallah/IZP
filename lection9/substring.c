#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findSubstring(const char* string, const char* substring)
{
    int len_string = strlen(string);
    int len_substring = strlen(substring);

    for (int i = 0; i < len_string; i++)
    {
        for (int j = 0; string[i+j] == substring[j]; j++)
        {
            if (substring[j+1] == '\0')
            {
                return i;
            }
        }
    }
    return -1;
}


char* shiftLeft(char* string, int LengthDifference, const int substringLength, const int position)
{
    int LengthString = strlen(string);

    for (int i = position + substringLength - LengthDifference; string[i] != '\0'; i++)
    {
        string[i] = string[i + LengthDifference];
    }

    char* new_string = realloc(string, LengthString - LengthDifference + 1);
    return new_string;
}


char* shiftRight(char* string, int len_diff, int len_substring, int position)
{
    int len_string = strlen(string);

    char* new_arr = realloc(string, len_string + len_diff);

    for (int i = len_string; i > position; i--)
    {
        new_arr[i + len_diff] = new_arr[i];
    }

    return new_arr;
}


void replaceSubstringOfSameLength(char* string, const char* substring, const char* newSubstring)
{
    int start = findSubstring(string, substring);

    int len_newSubstring = strlen(newSubstring);
    int len_substring = strlen(substring);

    for (int i = start, j = 0; j < len_newSubstring; i++, j++)
    {
        string[i] = newSubstring[j];
    }
}

char* replaceSubstringOfOtherLength(char* string, const char* substring, const char* newSubstring)
{
    int position = findSubstring(string, substring);

    int len_newSubstring = strlen(newSubstring);
    int len_substring = strlen(substring);

    char* new_string;

    if (len_newSubstring < len_substring)
    {
        new_string = shiftLeft(string, len_substring - len_newSubstring, len_substring, position);

        for (int i = position; i < len_newSubstring + position; i++)
        {
            new_string[i] = newSubstring[i-position];
        }
    }

    if (len_newSubstring > len_substring)
    {
        new_string = shiftRight(string, len_newSubstring - len_substring , len_substring, position);

        for (int i = position; i < len_newSubstring + position; i++)
        {
            new_string[i] = newSubstring[i-position];
        }
    }
    return new_string;
}

int main(void)
{
    char* string = malloc(sizeof(char));
    printf("Input string: ");
    scanf("%s", string);

    char* substring = malloc(sizeof(char));
    printf("Input substring: ");
    scanf("%s", substring);

    char* newSubstring = malloc(sizeof(char));
    printf("Input new substring: ");
    scanf("%s", newSubstring);

    if (strlen(substring) == strlen(newSubstring))
    {
        replaceSubstringOfSameLength(string, substring, newSubstring);
        printf("%s\n", string);
    }

    else
    {
        char* new_string = replaceSubstringOfOtherLength(string, substring, newSubstring);
        printf("%s\n", new_string);
    }

}


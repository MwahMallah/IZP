#include <stdio.h>

int main(void)
{
    char sentence[] = "I'm Nastya Mironova";
    char ch;

    int length = 0;
    int i = 0;

    ch = sentence[i];

    while (ch != '\0')
    {
        length++;
        i++;
        ch = sentence[i];
    }

    printf("%i", length);
    return 0;
}
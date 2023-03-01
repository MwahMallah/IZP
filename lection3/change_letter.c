#include <stdio.h>

int main(void)
{
    int word_length = 5;
    char our_letter = 'g';
    char word[] = "govno";

    for (int i = 0; i < word_length; i++)
    {
        if (word[i] == our_letter)
        {
            word[i] = '-';
        }
    }

    printf("%s - new word", word);
}
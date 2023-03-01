#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int word_length = 5;
    char word[] = "govno";
    char new_word[word_length];

    for (int i = 0; i < word_length; i++)
    {
        new_word[i] = toupper(word[i]);
    }

    printf("%s - new word", new_word);
}
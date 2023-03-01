#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[] = "hello world, my name is Nastya";
    int sentence_length = strlen(sentence);

    int word_counter = 0;


    for (int i = 0; i < sentence_length; i++)
    {
        if (sentence[i] = ' ')
        {
            word_counter++;
        }
    }

    printf("%i", word_counter);
    return 0;
}
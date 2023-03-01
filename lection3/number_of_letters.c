#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int word_length = 5;
    char word[] = "govno";

    int number_of_letters = 0;
    int number_of_nums = 0;

    for (int i = 0; i < word_length; i++)
    {
        if (isalpha(word[i]) != 0)
        {
            number_of_letters++;
        }

        else if (isdigit(word[i]) != 0)
        {
            number_of_nums++;
        }
    }

    printf("retezec ma %i - pismen a %i - cislic\n", number_of_letters, number_of_nums);
}

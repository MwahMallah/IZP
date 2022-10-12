#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//number of characters in one line
int MAX_NUMBER_IN_LINE = 100;

//two-dimensional array, which represents number to charachter relationship 
//2 -> ('a','b','c'), 3 -> ('d','e','f') and so on 
char number_to_letter[10][4] = {{'+'},{},{'a', 'b', 'c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},{'m','n','o'},{'p','q','r','s'},
{'t','u','v'},{'w','x','y','z'}};


void print_all_contacts(char*);
//make !!!!!!
//void check_if_in_line(char*);

int main(int argc, char* argv[])
{
    //array of characters in one line of seznam.txt
    char str[MAX_NUMBER_IN_LINE];

    // checks if there is no arguments
    if (argc == 1)
    {
        // prints all contacts from the list
        print_all_contacts(str);
        return 0;
    }

    //stores argument in a variable
    char* phone_input = argv[1];
    //finds length of argument
    int length_of_input = strlen(phone_input);

    while (fgets(str, MAX_NUMBER_IN_LINE, stdin) != NULL)
    {
        for (int i = 0; i < length_of_input; i++)
        {

            //converts char in phone_input to int and stores in index
            int index_of_char = phone_input[i] - '0';

            for (int j = 0; j < 4; j++)
            {
                printf("%c\n", number_to_letter[index_of_char][j]);

                for (int k = 0; k < MAX_NUMBER_IN_LINE; k++)
                {
                    printf("%c", str[k]);
                }
            }
        }
    }
}


void print_all_contacts(char str[])
{
    
    //reads line untill there are lines
    while (fgets(str, MAX_NUMBER_IN_LINE, stdin) != NULL)
    {
        //removes newline character and writes name of person
        str[strlen(str) - 1] = '\0';
        printf("%s, ", str);

        //reads number of person and prints it 
        fgets(str, 100, stdin);
        printf("%s", str);
    }
}

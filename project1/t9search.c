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
//int check_name(char*, int, char*);
int check_phone_number(char*, int, char*);

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
    char phone_number[MAX_NUMBER_IN_LINE];
    int person_counter = 0;

    //stores names of persons to str variable, untill file is not empty
    while (fgets(str, MAX_NUMBER_IN_LINE, stdin))
    {
        //stores phone number of person to variable
        fgets(phone_number, MAX_NUMBER_IN_LINE, stdin);

        //checks if phone input is equal to sequence in name
        //or in phone number
        /*if ((check_name(phone_input, length_of_input, str) == 0) || (check_phone_number(phone_input, length_of_input, phone_number) == 0))
        {
            printf("%s %s", str, phone_number);
            return 0;
        } */

        if ((check_phone_number(phone_input, length_of_input, phone_number) == 0))
        {
            str[strlen(str) - 1] = '\0';
            printf("%s, %s", str, phone_number);
            person_counter++;
        }
    }

    if (person_counter == 0)
    {
        printf("Not found\n");
        return 0;
    }

    return 0;
}


void print_all_contacts(char str[])
{
    //reads every line untill file is not empty
    while (fgets(str, MAX_NUMBER_IN_LINE, stdin) != NULL)
    {
        //removes newline character and prints name of person
        str[strlen(str) - 1] = '\0';
        printf("%s, ", str);

        //reads phone number of person and prints it 
        fgets(str, 100, stdin);
        printf("%s", str);
    }
}

int check_phone_number(char* phone_input, int input_length, char* phone_number)
{
    int number_length = strlen(phone_number);
    int flag = 0;
    int counter = 0;
    int index_of_phone_number = -1;

    for (int i = 0; i < input_length; i++)
    {
        if (flag == 1)
        {
            return 1;
        }
        flag = 1;

        for (index_of_phone_number = index_of_phone_number+1; index_of_phone_number < number_length; index_of_phone_number++)
        {
            if (phone_input[i] == phone_number[index_of_phone_number])
            {
                printf ("%c\n", phone_number[index_of_phone_number]);
                flag = 0;
                counter++;
                break;
            }      
        }
    }

    if (counter == 0)
    {
        return 1;
    }

    return 0;
}

/* int check_name(char* phone_input, int input_length, char* name)
{
    int name_length = strlen(name);

    //checks every digit in a phone number
    for (int i = 0; i < input_length; i++)
    {
        int flag = 1;

        //finds index of number to letter array
        int index = phone_input[i] - '0';

        //checks every character in number to letter array
        for (int ch = 0; ch < 4; ch++)
        {
            for (int j = 0; j < name_length; j++)
            {
                if (number_to_letter[index][ch] == name[j])
                {
                    flag = 0;

                }
            }
        }
    }

    return 1;
} */

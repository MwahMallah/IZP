#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//number of characters in one line
int MAX_NUMBER_IN_LINE = 100;

//two-dimensional array, which represents number to charachter relationship 
//2 -> ('a','b','c'), 3 -> ('d','e','f') and so on 
char number_to_letter[10][4] = {{'+'},{},{'a', 'b', 'c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},{'m','o','n'},{'p','q','r','s'},
{'t','u','v'},{'w','x','y','z'}};


void print_all_contacts(char*);
int check_name(char*, int, char*);
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
        if ((check_name(phone_input, length_of_input, str) == 0) || (check_phone_number(phone_input, length_of_input, phone_number) == 0))
        {
            str[strlen(str)-1] = '\0';
            person_counter++;
            printf("%s, %s", str, phone_number);
        } 

    }

    if (person_counter == 0)
    {
        printf("Not found\n");
        return 1;
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
    int pass;
    int j = 0;

    //iterate over every digit in phone input
    for (int i = 0; i < input_length; i++)
    {
        pass = 1;
        //iterate over every digit in phone number, starting from the digit, where was last equality
        for (j; j < number_length; j++)
        {
            if (phone_input[i] == phone_number[j])
            {
                pass = 0;
                break;
            }
        }

        //usage of pass variable to check if this iteration of phone input was successfull 
        if (pass == 1)
        {
            return 1;
        }
    }

    return 0;
}

 int check_name(char* phone_input, int input_length, char* name)
{
    int name_length = strlen(name);
    int pass1, pass2;
    int j = 0;

    //iterate over every digit in phone input
    for (int i = 0; i < input_length; i++)
    {
        int index_to_letter = phone_input[i] - '0';
        pass1 = 1;
        pass2 = 1;
        int k = 0;
        while (k < 4)
        {
            //iterate over every digit in phone number, starting from the digit, where was last equality
            for (j; j < name_length; j++)
            {
                printf("%i. %c == %c\n", k, number_to_letter[index_to_letter][k], name[j]);
                if (number_to_letter[index_to_letter][k] == name[j])
                {
                    pass1 = 0;
                    pass2 = 0;
                    break;
                }
            }

            if (pass2 == 0)
            {
                break;
            }
            k++;
        }

        //usage of pass variable to check if this iteration of phone input was successfull 
        if (pass1 == 1)
        {
            return 1;
        }
    }

    return 0;
} 

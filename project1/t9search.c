#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char str[100];

    // checks if there is no arguments
    if (argc == 1)
    {
        // prints all contacts from the list
        while (fgets(str, 100, stdin) != NULL)
        {
            //removes newline character and writes name of person
            str[strcspn(str, "\n")] = '\0';
            printf("%s, ", str);

            //reads number of person and prints it 
            fgets(str, 100, stdin);
            printf("%s", str);
        }

        return 0;
    }

}
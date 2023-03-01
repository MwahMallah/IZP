#include <stdio.h>

char* check_if(char);

int main()
{
    char* arr2 = "help me";
    char* arr3 = "nadya";

    char j = '0';
    char* i = check_if(j);

    printf("%s", j);
}

char* check_if(char j)
{
    if (j == '0')
    {
        return arr2;
    }

    else 
    {
        return "22";
    }
}


#include <stdio.h>

int main(int argc, char* argv[])
{
    char str[100];
    if (argc == 1)
    {
        while (fgets(str, 100, stdin))
        {
            printf("%s", str);
        }
    }
}
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char a[3][8];
}
arr_to_string;

arr_to_string god_give_me_string(char* input)
{
    int input_len = strlen(input);
    arr_to_string input_to_string;
    for (int i = 0; i < input_len; i++)
    {
        switch (input[i])
        {
        case '0':
            strcpy(input_to_string.a[i], "+");
            break;
        case '1':
            break;
        case '2':
            strcpy(input_to_string.a[i], "abcABC");
            break;
        case '3':
            strcpy(input_to_string.a[i], "defDEF");
            break;
        case '4':
            strcpy(input_to_string.a[i], "ghiGHI");
            break;
        case '5':
            strcpy(input_to_string.a[i], "jklJKL");
            break;
        case '6':
            strcpy(input_to_string.a[i], "mnoMNO");
            break;
        case '7':
            strcpy(input_to_string.a[i], "pqrsPQRS");
            break;
        case '8':
            strcpy(input_to_string.a[i], "tuvTUV");
            break;
        case '9':
            strcpy(input_to_string.a[i], "wxyzWXYZ");
            break;
        default:
            break;
        }
    }
    return input_to_string;
}

int main(void)
{
    char input[3] = "234";
    arr_to_string input_to_string = god_give_me_string(input);

    printf("%c", input_to_string.a[1][2]);
}
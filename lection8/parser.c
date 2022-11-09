#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int xflag;
    int yflag;
    char* s;
    int n;
} ApplicationConfig;

int parseArguments(int argc, char* argv[], ApplicationConfig* applicationConfig)
{
    if (argc < 3 || argc > 6)
    {
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        if (strcmp("-x", argv[i]) == 0)
        {
            applicationConfig->xflag = 1;
            continue;
        }

        if (strcmp("-y", argv[i]) == 0)
        {
            applicationConfig->yflag = 1;
            continue;
        }

        if (strcmp("-s", argv[i]) == 0)
        {
            applicationConfig->s = argv[++i];
            continue;
        }
        
        if (strcmp("-n", argv[i]) == 0)
        {
            applicationConfig->n = atoi(argv[++i]);
            continue;
        }

        return 0;
    }

    if (applicationConfig->xflag == 1 && applicationConfig->yflag == 1)
    {
        return 0;
    }

    if (applicationConfig->s == NULL)
    {
        return 0;
    }

    return 1;
}


int main(int argc, char* argv[])
{
    ApplicationConfig* applicationconfig = malloc(sizeof(ApplicationConfig));

    applicationconfig->n = 0;
    applicationconfig->s = NULL;
    applicationconfig->xflag = 0;
    applicationconfig->yflag = 0;

    if (parseArguments(argc, argv, applicationconfig) == 1)
    {
        printf("is valid\n");
    }

    else 
    {
        printf("is not valid\n");
    }

    free(applicationconfig);
}
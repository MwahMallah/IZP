#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector
{
    int length;
    int* elements;
}
vector;

void init_vector(vector* v, char* vector_length)
{
    v->length = atoi(vector_length);
    v->elements = malloc(sizeof(int) * v->length);

    for (int i = 0; i < v->length; i++)
    {
        printf("Input %d's element: ", i + 1);
        scanf("%d", &v->elements[i]);
    }
}

void print_vector(vector* v)
{
    printf("[");
    for (int i = 0; i < v->length; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }

        printf("%d", v->elements[i]);
    }
    printf("]");
}

void mult_vector_const(vector* v, int constanta)
{
    for (int i = 0; i < v->length; i++)
    {
        v->elements[i] *= constanta;
    }
}

void vector_addition(vector* v, vector* u, vector* c)
{
    for (int i = 0; i < v->length; i++)
    {
        c->elements[i] = v->elements[i] + u->elements[i];
    }
}

int scalar_product(vector* v, vector* u)
{
    int sum = 0; 

    for (int i = 0; i < v->length; i++)
    {
        sum +=  v->elements[i] * u->elements[i];
    }
    return sum;
}

void vector_product(vector* v, vector* u, vector* c)
{
    if (v->length != 3)
    {
        printf("Can't count that hard\n");
        return ;
    }

    c->elements[0] = v->elements[1] * u->elements[2] - v->elements[2] * u->elements[1];
    c->elements[1] = v->elements[2] * u->elements[0] - v->elements[0] * u->elements[2];
    c->elements[2] = v->elements[0] * u->elements[1] - v->elements[1] * u->elements[0];
}

int main(int argc, char* argv[])
{
    vector* v = malloc(sizeof(vector));

    init_vector(v, argv[1]);

    printf("\n");

    printf("Initial vector: ");
    print_vector(v);
    printf("\n");

    if (argc >= 3)
    {
        if (strcmp(argv[2], "-mc") == 0)
        {
            int c;
            printf("Input constant: ");
            scanf("%d", &c);

            mult_vector_const(v, c);

            printf("New vector: ");
            print_vector(v);
        }

        if (strcmp(argv[2], "-a") == 0)
        {
            vector* u = malloc(sizeof(vector));
            char int_str[20]; 
            sprintf(int_str, "%d", v->length);

            printf("Second vector: \n");
            init_vector(u, int_str);

            vector* c = malloc(sizeof(vector));
            c->length = u->length;
            c->elements = malloc(sizeof(int)* (c->length));

            vector_addition(v, u, c);

            printf("\n");
            printf("New vector: ");
            print_vector(c);

            free(c->elements);
            free(c);

            free(u->elements);
            free(u);
        }

        if (strcmp(argv[2], "-sp") == 0)
        {
            vector* u = malloc(sizeof(vector));
            char int_str[20]; 
            sprintf(int_str, "%d", v->length);

            printf("Second vector: \n");
            init_vector(u, int_str);

            int c = scalar_product(v, u);

            printf("Scalar product: %d", c);

            free(u->elements);
            free(u);
        }

        if (strcmp(argv[2], "-vp") == 0)
        {
            vector* u = malloc(sizeof(vector));
            char int_str[20]; 
            sprintf(int_str, "%d", v->length);

            printf("Second vector: \n");
            init_vector(u, int_str);

            vector* c = malloc(sizeof(vector));
            c->length = u->length;
            c->elements = malloc(sizeof(int)* (c->length));

            vector_product(v, u, c);

            printf("\n");
            printf("New vector: ");
            print_vector(c);

            free(c->elements);
            free(c);

            free(u->elements);
            free(u);
        }
    }

    free(v->elements);
    free(v);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int* values;
    int size;
} vector;

int vector_alloc(vector* vector, unsigned int size)
{
    vector->values = malloc(size * sizeof(vector));
    vector->size = size;
    return size;
}

void vector_init(vector* v)
{
    for (int i = 0; i < v->size; i++)
    {
        printf("enter %d's argument: ", i);
        scanf("%d", &v->values[i]);
    }
}

void vector_d(vector* v)
{
    free(v);
    v = NULL;
}

int main(int argc, char* argv[])
{
    vector* v = malloc(sizeof(vector));
    unsigned int size = *argv[1] - '0';

    vector_alloc(v, size);
    vector_init(v);

    printf("array is now = [");
    for (int i = 0; i < v->size - 1; i++)
    {
        printf("%d ", v->values[i]);
    }
    printf("%d]\n", v->values[v->size-1]);

    vector_d(v);
}
#include <stdio.h>
#include <stdlib.h>

int rel_size = 5;

typedef struct 
{
    int first;
    int second;
} pair_t;

int is_function(pair_t rel[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (rel[i].first == rel[j].first)
            {
                return 1;
            }
        }
    }

    return 0;
}


void rel_minmax(pair_t rel[5], int* min, int* max)
{
    *min = rel[0].second;
    *max = rel[0].second;
    
    for (int i = 0; i < 5; i++)
    {
        if (*max < rel[i].second)
        {
            *max = rel[i].second;
        }
        if (*min > rel[i].second)
        {
            *min = rel[i].second;
        }
    }
}

void pair_invert(pair_t* point)
{
    int tmp = point->first;
    point->first = point->second;
    point->second = tmp;
}

int main(void)
{
    pair_t rel[5] = {{1,2}, {2,4}, {3,6}, {4,8}, {5,10}};

    pair_t* point = malloc(sizeof(pair_t));
    point->first = 1;
    point->second = 2;

    pair_invert(point);

    printf("%d - first, %d - second\n", point->first, point->second);

}
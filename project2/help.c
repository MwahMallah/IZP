#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h> // sqrtf
#include <limits.h> // INT_MAX

typedef struct obj_t
{
    int id;
    int x;
}
obj_t;

typedef struct list
{
    int id;
    obj_t* obj;
}
list;

void init_list(list** l)
{
    *l = (list*) malloc(sizeof(list));
    (*l)->obj = (obj_t*) malloc(sizeof(obj_t));
}

int main(int argc, char *argv[])
{
    list** lists = malloc(sizeof(list*) * 4);

    for (int i = 0; i < 4; i++)
    {
        init_list(&lists[i]);
    }

    for (int j = 0; j < 4; j++)
    {
        lists[j]->obj->id = j;
    }

    printf("%d\n", lists[2]->obj->id);

    free(lists);
}
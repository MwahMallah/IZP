#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h> // sqrtf
#include <limits.h> // INT_MAX

#define dint(i) printf(" - " __FILE__ ":%u: " #i " = %d\n", __LINE__, i)

struct obj_t {
    int id;
    float x;
    float y;
};

struct cluster_t {
    int size;
    int capacity;
    struct obj_t *obj;
};

void init_cluster(struct cluster_t *c, int cap)
{
    assert(c != NULL);
    assert(cap >= 0);

    // TODO
    c->capacity = cap;
    c->obj = malloc(sizeof(struct obj_t) * cap);
    
    if (c->obj == NULL)
    {
        c->capacity = 0;
    }

    c->obj[0].id = 2;
    printf("%d\n", c->obj[0].id);
}

int main(int argc, char *argv[])
{
    struct cluster_t *clusters;

    // TODO
    clusters = malloc(sizeof(struct cluster_t));

    init_cluster(clusters, 2);
    printf("%d\n", clusters->capacity);
}
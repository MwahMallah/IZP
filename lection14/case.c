#include <stdio.h>

titme* listFindMax(tlitst* list)
{
    titem* max = list->head;

    for (titem* tmp = max->next; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->data.pay > max->data.pay)
        {
            max = tmp;
        }
    }

    return max;
}

int main(void)
{
    
}
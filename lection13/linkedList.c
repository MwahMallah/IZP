#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    char name[10];
    char surname[15];
    int year;
}
person;

typedef struct node
{
    person data;
    struct node* next;
}
node;

typedef struct linkedList
{
    node* head;
    node* tail;
}
linkedList;

void listInit(linkedList*);
int makePerson(person*);
void insertFirst(linkedList*, person);
void makeList(linkedList*, person);
void writeList(linkedList*);
void deleteList(linkedList*);

int main(void)
{
    linkedList list;
    person pers;

    listInit(&list);
    makeList(&list, pers);

    writeList(&list);
    deleteList(&list);
}

void listInit(linkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
    return;
}

int makePerson(person* pers)
{
    printf("Input person data: ");
    int i = scanf("%s %s %d", pers->name, pers->surname, &pers->year);

    if (i != 3 || i == EOF)
    {
        return -1;
    }
    return 0;
}

void insertFirst(linkedList* list, person pers)
{
    node* newNode = malloc(sizeof(node));

    newNode->data = pers;
    
    newNode->next = list->head;
    list->head = newNode;
    return;
}

void makeList(linkedList* list, person pers)
{
    while (makePerson(&pers) != -1)
    {
        insertFirst(list, pers);
    }
    return;
}

void writeList(linkedList* list)
{
    int i = 1;

    for (node* tmp = list->head; tmp != NULL; tmp = tmp->next, i++)
    {
        printf("%d. %s %s %d\n", i, tmp->data.name, tmp->data.surname, tmp->data.year);
    }

    return;
}

void deleteList(linkedList* list)
{
    while (list->head != NULL)
    {
        node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
}

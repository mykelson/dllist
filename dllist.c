#include <stdio.h>
#include <stdlib.h>

typedef struct dllist
{
    int val;
    struct dllist* next;
    struct dllist* prev;
}
dllnode;

dllnode* nnode1;

dllnode* create(int n);
dllnode* insert(dllnode* list, int m);
dllnode* search(dllnode* list , int n);
void delete(dllnode* target);


int main(void)
{
    nnode1 = create(1);
    nnode1 = insert(nnode1, 2);
    nnode1 = insert(nnode1, 3);
    nnode1 = insert(nnode1, 24);
    nnode1 = insert(nnode1, 5);

    dllnode* x = search(nnode1, 2);
    delete(x);
}


dllnode* create(int n)
{
    dllnode* head = malloc(sizeof(dllnode));
    if (head != NULL)
    {
        head->val = n;
        head->next = NULL;
        head->prev = NULL;
    }
    return head;
}


dllnode* insert(dllnode* list, int m)
{
    dllnode* new_node = malloc(sizeof(dllnode));
    if (new_node != NULL)
    {
        new_node->val = m;
        new_node->next = list;
        new_node->prev = NULL;
        list->prev = new_node;
    }
    return new_node;
}


dllnode* search(dllnode* list , int n)
{
    dllnode* ptr = list;
    while (ptr != NULL)
    {
        if (ptr->val == n)
        {
            return ptr;
        }
         ptr = ptr->next;
    }
   
}


void delete(dllnode* target)
{
    dllnode* temp = target->prev;
    dllnode* temp1 = target->next;
    target->prev = temp1;
    target->next = temp;
    free(target);
}

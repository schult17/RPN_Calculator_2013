#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static struct stackNode *NewStackNode(float item)
{
    struct stackNode *new = malloc(sizeof(struct stackNode));
    new->data = item;
    new->next = NULL;
    return new;
}

int Push(struct stackNode** top, float item)
{
    struct stackNode *new = NewStackNode(item);
    struct stackNode *temp = *top;
    *top = new;
    new->next = temp;
    return 0;
}

int Pop(struct stackNode** top, float* popped)
{
    if(*top == NULL)
    {
        return -1;
    }
    else
    {
        struct stackNode *temp = *top;
        *top = temp->next;
        *popped = temp->data;
        free(temp);
        return 0;
    }
}

int Peek(struct stackNode* top, float* data)
{
    if(top == NULL)
    {
        return -1;
    }
    else
    {
        *data = top->data;
        return 0;
    }
}

int PrintStack(struct stackNode* top)
{
    if(top == NULL)
    {
        return -1;
    }
    else
    {
        struct stackNode *curr = top;
        printf("Current Stack:");
        while(curr != NULL)
        {
            printf(" %.2f", curr->data);
            curr = curr->next;
        }
        printf("\n");
        return 0;
    }
}

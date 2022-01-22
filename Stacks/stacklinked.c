#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} stacknode;

void push(stacknode **st, int ele)
{
    //st points to the topmost node
    stacknode *temp;
    temp = malloc(sizeof(stacknode));
    temp->data = ele;
    temp->link = NULL;
    if (*st == NULL)
    {
        (*st) = temp;
        (*st)->link = NULL;
    }
    else
    {
        temp->link = *st; //linking
        *st = temp;
    }
}

void pop(stacknode **st)
{
    stacknode *temp; //temporary to hold first node
    temp = *st;
    if (*st)
    {
        (*st) = (*st)->link;
        free(temp);
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

void display(stacknode **st)
{
    stacknode *disp;
    disp = *st;
    while (disp)
    {
        printf("%d\t", disp->data);
        disp = disp->link;
    }
}
int main()
{
    stacknode *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    printf("Adding 4 elements \n");
    display(&top);
    pop(&top);
    pop(&top);
    printf("\n");
    printf("After deleting two elements.\n");
    display(&top);
}
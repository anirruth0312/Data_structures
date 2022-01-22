#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
};
typedef struct node dll_node;

dll_node *createnode(int ele)
{
    dll_node *newnode;
    if (newnode)
    {
        newnode = (dll_node *)malloc(sizeof(dll_node));
        newnode->llink = NULL;
        newnode->rlink = NULL;
        newnode->data = ele;
    }
    else
        printf("Memory not allocated");
    return newnode;
}

void insert_front(dll_node **dstart, int ele) // dstart points to starting address of node
{
    dll_node *newnode;
    newnode = createnode(ele);
    if (*dstart == NULL)
    {
        *dstart = newnode;
    }
    else
    {
        newnode->rlink = *dstart;
        (*dstart)->llink = newnode;
        *dstart = newnode;
    }
}

void insert_end(dll_node **dstart, int ele)
{
    dll_node *temp, *newnode;
    newnode = createnode(ele);
    if (*dstart == NULL)
    {
        *dstart = newnode;
    }
    else
    {
        temp = *dstart;
        while (temp->rlink != NULL)
        {
            temp = temp->rlink;
        }
        temp->rlink = newnode;
        newnode->llink = temp;
    }
}

void insert_at_pos(dll_node **dstart, int ele, int pos)
{
    dll_node *newnode, *temp;
    int i = 1;
    if (pos == 1 || *dstart == NULL) // if list is empty or first position
    {
        insert_front(dstart, ele);
    }
    else
    {
        temp = *dstart;
        while (i < pos - 1 && temp->rlink != NULL) // understanfing prob
        {
            temp = temp->rlink;
            i++;
        }
        if (i == pos - 1)
        {
            newnode->rlink = temp->rlink;
            newnode->llink = temp;
            temp->rlink = newnode;
        }
        else if (temp->rlink == NULL) // last node
        {
            newnode->llink = temp;
            temp->rlink = newnode;
        }
    }
}

// Deletion

void delete_front(dll_node **dstart)
{
    dll_node *temp;
    if (*dstart == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        temp = *dstart;
        *dstart = (*dstart)->rlink;
        free(temp);
        (*dstart)->llink = NULL;
    }
}

void delete_end(dll_node **dstart)
{
    dll_node *temp;
    temp = *dstart;
    while (temp->rlink != NULL)
    {
        temp = temp->rlink;
    }
    (temp->llink)->rlink = NULL;
    temp->llink = NULL;
    free(temp);
}

void delete_pos(dll_node **dstart, int pos)
{
    dll_node *temp;
    if (*dstart == NULL)
    {
        printf("The list is empty\n");
    }
    else if (pos == 1)
    {
        delete_front(dstart);
    }
    else
    {
        dll_node *temp;
        int i = 0;
        temp = *dstart;
        while (temp->rlink != NULL && i < pos - 1)
        {
            temp = temp->rlink;
            i++;
        }
        if (i == pos - 1)
        {
            if (temp->rlink == NULL) // Last position
            {
                delete_end(dstart);
            }
            else
            {
                temp->rlink->llink = temp->llink; // linking next node to previous node that preceeded deleted node
                temp->llink->rlink = temp->rlink;
                free(temp);
            }
        }
        else
        {
            printf("The list is empty.\n");
        }
    }
}

void display(const dll_node *dstart)
{
    while (dstart != NULL)
    {
        printf("%d\t", dstart->data);
        dstart = dstart->rlink;
    }
    printf("\n");
}

int main()
{
    dll_node *start = NULL;
    insert_front(&start, 54);
    insert_front(&start, 76);
    insert_front(&start, 66);
    insert_front(&start, 5);
    insert_end(&start, 98);
    insert_end(&start, 23);
    printf("Printing list:\n");
    display(start);
    insert_at_pos(&start, 89, 1);
    printf("\nAdding 89 at position 1:\n");
    display(start);
    delete_front(&start);
    printf("\nDeleting from start:\n");
    display(start);
    delete_end(&start);
    printf("\nDeleting from last:\n");
    display(start);
    printf("Deleting at a position 3\n");
    delete_pos(&start, 3);
    display(start);
    return 0;
}
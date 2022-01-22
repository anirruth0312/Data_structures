#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *link;
} SLL_NODE;

SLL_NODE *createnode(int ele)
{
    SLL_NODE *temp = malloc(sizeof(SLL_NODE));
    if (temp == NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        temp->data = ele;
        temp->link = NULL;
    }
    return temp;
}

void insert_at_front(SLL_NODE **dstart, int ele)
{
    SLL_NODE *newnode = createnode(ele);
    if (*dstart == NULL)
    {
        *dstart = newnode;
    }
    else
    {
        newnode->link = *dstart;
        *dstart = newnode;
    }
}

SLL_NODE *insert_at_rear(SLL_NODE *dstart, int ele) // changes made in dstart not visible in main function
{
    SLL_NODE *newnode = createnode(ele);
    if (dstart == NULL)
    {
        dstart = newnode;
    }
    else
    {
        while (dstart->link != NULL)
        {
            dstart = dstart->link;
        }
        dstart->link = newnode;
    }
    return dstart;
}

SLL_NODE *insert_at_pos(SLL_NODE *pstart, int ele, int pos)
{
    SLL_NODE *newnode = createnode(ele);
    if (pos == 1 || pstart == NULL)
    {
        insert_at_front(&pstart, ele);
    }
    else
    {
        int i = 1;
        SLL_NODE *dstart = pstart;
        while (i < pos - 1 && dstart->link != NULL)
        {
            dstart = dstart->link;
            i++;
        }

        if (i == pos - 1)
        {
            if (dstart->link == NULL)
            {
                dstart = insert_at_rear(dstart, ele);
            }
            else
            {
                newnode->link = dstart->link;
                dstart->link = newnode;
            }
        }
    }
    return pstart;
}

SLL_NODE *delete_front(SLL_NODE **start)
{
    SLL_NODE *temp;
    temp = *start;
    if (temp == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        *start = (*start)->link;
        free(temp);
        temp = NULL;
    }
}

SLL_NODE *delete_end(SLL_NODE **start)
{
    SLL_NODE *present;
    SLL_NODE *prev;
    if (*start == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        int i = 1;
        present = *start;
        while (present->link != NULL)
        {
            prev = present;
            present = present->link;
        }
        prev->link = NULL;
        free(present);
    }
}

SLL_NODE *delete_pos(SLL_NODE *start, int pos)
{
    SLL_NODE *present = start;
    SLL_NODE *prev;
    int i = 1;
    if (pos == 1)
    {
        delete_front(&start);
    }
    else
    {
        while (i < pos && present->link != NULL)
        {
            prev = present;
            present = present->link;
            i++;
        }
        // element is in the middle
        if (i == pos && present->link != NULL)
        {
            prev->link = present->link;
            free(present);
            present = NULL;
        }
        else if (i == pos && present->link == NULL)
        {
            delete_end(&start);
        }
        else
        {
            printf("Invalid position\n");
        }
    }
    return start;
}

void display(SLL_NODE *dstart)
{

    if (dstart == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (dstart != NULL)
        {
            printf("%d\t", dstart->data);
            dstart = dstart->link;
        }
    }
    printf("\n");
}
int main()
{
    SLL_NODE *start;
    start = NULL;
    insert_at_front(&start, 56);
    insert_at_front(&start, 52);
    insert_at_front(&start, 25);
    insert_at_rear(start, 98);
    insert_at_rear(start, 109);
    start = insert_at_pos(start, 10, 6);
    display(start);
    delete_front(&start);
    delete_end(&start);
    printf("After deleting two elements at front and rear \n");
    display(start);
    start = delete_pos(start, 3);
    printf("After deleting element at pos 3\n");
    display(start);
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node csll_node;

csll_node *createnode(int ele)
{
    csll_node *newnode;
    newnode = (csll_node *)malloc(sizeof(csll_node));
    if (newnode)
    {
        newnode->data = ele;
        newnode->link = NULL;
    }
    else
        printf("Memory Not allocated\n");
    return newnode;
}

void insert_front(csll_node **ptail, int ele)
{
    csll_node *newnode;
    newnode = createnode(ele);
    if (*ptail == NULL)
    {
        *ptail = newnode;
        newnode->link = *ptail;
    }
    else
    {
        newnode->link = (*ptail)->link;
        (*ptail)->link = newnode;
    }
}

void insert_end(csll_node **ptail, int ele)
{
    csll_node *newnode;
    newnode = createnode(ele);
    if (*ptail == NULL)
    {
        *ptail = newnode;
        newnode->link = *ptail;
    }
    else
    {
        newnode->link = (*ptail)->link;
        (*ptail)->link = newnode;
        *ptail = newnode;
    }
}

void insert_pos(csll_node **ptail, int ele, int pos)
{
    csll_node *newnode;
    newnode = createnode(ele);
    if (*ptail == NULL || pos == 1)
    {
        newnode->link = (*ptail)->link;
        (*ptail)->link = newnode;
    }
    else
    {
        int i = 1;
        csll_node *temp;       //temp to traVrse the list
        temp = (*ptail)->link; // temp points to starting node
        while (temp != *ptail && i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        //if first condtion in while loop fails temp points to last node
        //if second condition fails temp has reached the position
        if (i == pos - 1)
        {
            if (temp = *ptail) //last node
            {
                newnode->link = (*ptail)->link;
                (*ptail)->link = newnode;
                *ptail = newnode;
            }
            else //node before required position
            {
                newnode->link = temp->link;
                temp->link = newnode;
            }
        }
        else
        {
            printf("Node not found\n");
        }
    }
}

void delete_front(csll_node **ptail)
{
    if (*ptail == NULL)
    {
        printf("List is empty\n");
    }
    else if ((*ptail)->link == *ptail) //only one node in the list
    {
        free(*ptail);
        *ptail = NULL;
    }
    else
    {
        csll_node *temp; //to hold first node
        temp = (*ptail)->link;
        (*ptail)->link = temp->link;
        free(temp);
        temp = NULL;
    }
}

void delete_end(csll_node **ptail)
{
    if (*ptail == NULL)
    {
        printf("List is empty\n");
    }
    else if ((*ptail)->link == *ptail) //only one node in the list
    {
        free(*ptail);
        *ptail = NULL;
    }
    else
    {
        csll_node *temp; //to find the second last node
        temp = (*ptail)->link;
        while (temp->link != *ptail)
        {
            temp = temp->link;
        }
        temp->link = temp->link->link; //linking temp to first node
        free(*ptail);
        *ptail = temp;
    }
}

void delete_pos(csll_node **ptail, int pos)
{
    if (*ptail == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        delete_front(ptail);
    }
    else
    {
        int i = 1;
        csll_node *temp; //to traverse through the list
        temp = (*ptail)->link;
        while (temp != *ptail && i != pos - 1)
        //if first condtion in while loop fails temp points to last node
        //if second condition fails temp has reached the position
        {
            temp = temp->link;
            i++;
        }
        if (i == pos - 1) //previous node before pos
        {
            if (temp == *ptail)
            {
                delete_end(ptail);
            }
            else
            {
                csll_node *deltemp;
                deltemp = temp->link;
                temp->link = temp->link->link;
                free(deltemp);
                deltemp = NULL;
            }
        }
        else
            printf("Node not founf\n");
    }
}

void display(csll_node *ptail)
{
    csll_node *disp = ptail->link;
    do
    {
        printf("%d\t", disp->data);
        disp = disp->link;
    } while (disp != ptail->link);
    printf("\n");
}

int main()
{
    csll_node *tail;
    tail = NULL;
    printf("The list is :\n");
    insert_front(&tail, 56);
    insert_front(&tail, 23);
    insert_front(&tail, 98);
    insert_end(&tail, 14);
    insert_end(&tail, 74);
    display(tail);
    printf("Inserting 63 at pos 3\n");
    insert_pos(&tail, 63, 3);
    display(tail);
    printf("Inserting 68 at pos 2\n");
    insert_pos(&tail, 68, 2);
    display(tail);
    printf("Deletion :\n");
    delete_front(&tail);
    delete_front(&tail);
    delete_end(&tail);
    delete_end(&tail);
    display(tail);
    printf("Deleting from pos 2:\n");
    delete_pos(&tail, 2);
    display(tail);
}

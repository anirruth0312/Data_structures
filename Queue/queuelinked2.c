#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *link;
} queue;

queue *front = NULL;
queue *rear = NULL;

queue *create(int ele)
{
    queue *newblock;
    newblock = malloc(sizeof(queue));
    newblock->data = ele;
    newblock->link = NULL;
    return newblock;
}

void insertqueue(int ele)
{
    queue *newnode = NULL;
    newnode = create(ele);
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}

void deletequeue()
{
    queue *temp;
    temp = front;
    if (temp == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        front = front->link;
        free(temp);
    }
}

void display()
{
    queue *temp;
    temp = front;

    while (temp)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    insertqueue(10);
    insertqueue(20);
    insertqueue(30);
    insertqueue(40);
    insertqueue(50);
    printf("Adding 5 elements to the queue.\n");
    display();
    deletequeue();
    deletequeue();
    deletequeue();
    printf("Deleting two elements.\n");
    display();
}
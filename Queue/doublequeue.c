// double ended queue using arrays
// yes
#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int *Q;
    int front;
    int rear;
    int capacity;
    int size;

} dqueue;

void initqueue(dqueue *pq, int c)
{
    pq->front = -1;
    pq->rear = -1;
    pq->Q = NULL;
    pq->capacity = c;
    pq->size = 0;
}

void createqueue(dqueue *pq)
{
    pq->Q = malloc(sizeof(int) * pq->capacity);
}

int isempty(dqueue *pq)
{
    if (pq->front == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull(dqueue *pq)
{
    if (pq->front == pq->capacity - 1)
        return 1;
    else
        return 0;
}

void insertqueue_front(dqueue *pq, int ele)
{
    if (!isfull(pq))
    {
        if (isempty(pq))
        {
            pq->front = 0;
            pq->rear = 0;
            pq->Q[0] = ele;
        }
        else
        {
            pq->front = (pq->front - 1 + pq->size) % pq->size;
            pq->Q[pq->front] = ele;
        }
        pq->size = pq->size + 1;
    }
    else
    {
        printf("Queue is full\n");
        return;
    }

    printf("%d\n\n", pq->front);
}

void insertqueue_rear(dqueue *pq, int ele)
{
    if (isempty(pq))
    {
        pq->front = 0;
        pq->rear = 0;
        pq->Q[pq->rear] = ele;
        pq->size++;
    }
    else if (isfull(pq))
    {
        printf("Queue is full\n");
    }
    else
    {
        pq->rear = (pq->rear + 1) % pq->size;
        pq->Q[pq->rear] = ele;
        pq->size++;
    }
}

int dequeue_front(dqueue *pq)
{
    int popele;
    if (isempty(pq))
    {
        printf("Queue is empty.\n");
    }
    else if (pq->front == pq->rear) // one element is left
    {
        popele = pq->Q[pq->front];
        pq->front = -1;
        pq->rear = -1;
    }
    else
    {
        popele = pq->Q[pq->front];
        pq->front = (pq->front + 1) % pq->size;
    }
    return popele;
}

int dequeue_rear(dqueue *pq)
{
    int popele;
    if (isempty(pq))
    {
        printf("Queue is empty.\n");
    }
    else if (pq->front == pq->rear) // one element is left
    {
        popele = pq->Q[pq->rear];
        pq->rear = -1;
        pq->front = -1;
        return popele;
    }
    else
    {
        popele = pq->Q[pq->rear];
        pq->rear = (pq->rear - 1 + pq->size) % pq->size;
        return popele;
    }
    return -99;
}

void display(dqueue *pq)
{
    if (isempty(pq))
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        int i;
        for (i = pq->front; i != pq->rear; i = (i + 1) % pq->size)
        {
            printf("%d\t", pq->Q[i]);
        }
        printf("%d", pq->Q[pq->rear]);
    }
}

int main()
{
    dqueue pq;
    int c;
    // printf("Enter the size of the queue.\n");
    // scanf("%d", &c);
    initqueue(&pq, 10);
    createqueue(&pq);
    insertqueue_front(&pq, 10);
    insertqueue_front(&pq, 20);
    insertqueue_front(&pq, 30);
    insertqueue_front(&pq, 30);
    display(&pq);
}
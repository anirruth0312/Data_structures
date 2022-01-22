#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int *Q;
    int front;
    int rear;
    int capacity;
};
typedef struct queue queue;

void initqueue(queue *pq, int c)
{
    pq->Q = NULL;
    pq->rear = -1;
    pq->front = -1;
    pq->capacity = c;
}

void createqueue(queue *pq)
{
    pq->Q = malloc(sizeof(int) * pq->capacity);
}

int isempty(queue *pq)
{
    return (pq->front == -1);
}

int isfull(queue *pq)
{
    return (pq->rear == pq->capacity - 1);
}

void insert_queue(queue *pq, int ele)
{
    if (isfull(pq))
    {
        printf("Queue is full\n");
    }
    if (pq->front == -1)
    {
        pq->front = 0;
        pq->rear = 0;
        pq->Q[pq->front] = ele;
    }
    else
    {
        pq->rear = pq->rear + 1;
        pq->Q[pq->rear] = ele;
    }
}

int delete_queue(queue *pq)
{
    int ele = 0;
    if (isempty(pq))
    {
        printf("Queue is empty\n");
    }
    if (pq->front == pq->rear)
    {
        ele = pq->Q[pq->rear];
        pq->rear = -1;
        pq->front = -1;
    }
    else
    {
        ele = pq->Q[pq->front];
        pq->front++;
    }
}
void display(queue *pq)
{
    if (pq->front != -1)
    {
        for (int i = pq->front; i <= pq->rear; i++)
        {
            printf("%d\t", pq->Q[i]);
        }
    }
}

void destroy(queue *pq)
{
    free(pq->Q);
    free(pq);
}

int main()
{
    int c;
    queue pq;
    printf("Enter the size of the queue :");
    scanf("%d", &c);
    initqueue(&pq, c);
    createqueue(&pq);
    insert_queue(&pq, 10);
    insert_queue(&pq, 20);
    insert_queue(&pq, 30);
    insert_queue(&pq, 40);
    insert_queue(&pq, 50);
    printf("After inserting five elements.\n");
    display(&pq);
    printf("\n");
    delete_queue(&pq);
    delete_queue(&pq);
    delete_queue(&pq);
    printf("After deleting three elements.\n");
    display(&pq);
}
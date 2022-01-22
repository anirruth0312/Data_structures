#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct queue
{
    int capacity;
    int size;
    int front;
    int rear;
    int *q;
} queue;

void initq(queue *pq, int c)
{
    pq->q = NULL;
    pq->capacity = c;
    pq->rear = -1;
    pq->front = -1;
    pq->size = 0;
}

int create_queue(queue *pq)
{
    pq->q = malloc(sizeof(int) * pq->capacity);
}

int isempty(queue *pq)
{
    return (pq->front == -1 || pq->rear == -1 || pq->front == pq->rear + 1);
}

int enqueue(queue *pq, int ele)
{
    pq->rear = pq->rear + 1;
    pq->q[pq->rear] = ele;
    (pq->size)++;
    if (isempty(pq))
        pq->front = 0;
    return 1;
}

int dequeue(queue *pq)
{
    int ele;
    if (!isempty(pq))
    {
        if (pq->front == pq->rear)
        {
            ele = pq->q[pq->front];
            pq->front = -1;
            pq->rear = -1;
        }
        else
        {
            ele = pq->q[pq->front];
            pq->front = pq->front + 1;
        }
        (pq->size)--;
        return ele;
    }
    return -1;
}

int **createmat(int n)
{
    int **mat;
    int i;
    mat = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        mat[i] = (int *)malloc(sizeof(int) * n);
    return mat;
}

void bfs(int source, int **adjmat, int *visited, int n)
{
    int i, delvertex;
    queue *pq = (queue *)malloc(sizeof(queue));
    initq(pq, 10);
    create_queue(pq);
    visited[source] = 1;
    printf("%d\t", source);
    enqueue(pq, source);
    while (!isempty(pq))
    {
        delvertex = dequeue(pq);
        for (i = 0; i < n; i++)
        {
            if (adjmat[delvertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                printf("%d\t", i);
                enqueue(pq, i);
            }
        }
    }
}

void BFS(int source, int **adjmat, int *visited, int n)
{
    int i;
    bfs(source, adjmat, visited, n);
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            bfs(i, adjmat, visited, n);
    }
}

int main()
{
    int **adjmat;
    int visited[max];
    int n, i, j, source;
    printf("Enter the matrix size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    adjmat = createmat(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &adjmat[i][j]);
    }
    printf("Enter the source: ");
    scanf("%d", &source);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("BFS:\n");
    BFS(source, adjmat, visited, n);
    return 0;
}
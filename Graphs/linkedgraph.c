#include <stdlib.h>
#include <stdio.h>

typedef struct graphnode
{
    int vid;
    struct graphnode *link;
} graphnode;
typedef struct graphdetails
{
    int edges;
    int vertices;
    graphnode **graphptr;
} g_details;

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
        if (pq->front == pq->rear) // if one element is present in the queue
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

void allocgraph(g_details *ptr_graphdetails)
{
    ptr_graphdetails->graphptr = malloc(sizeof(graphnode *) * ptr_graphdetails->vertices);
    for (int i = 0; i < ptr_graphdetails->vertices; i++)
    {
        ptr_graphdetails->graphptr[i] = NULL;
    }
}

void readgraph(g_details *ptr_graphdetails)
{
    int i, j, choice;
    graphnode *start, *dstart, *newnode;
    // dstart for traversing the list
    for (int i = 0; i < ptr_graphdetails->vertices; i++)
    {
        for (int j = 0; j < ptr_graphdetails->vertices; j++)
        {
            scanf("%d", &choice);
            if (choice)
            {
                newnode = malloc(sizeof(graphnode));
                newnode->link = NULL;
                newnode->vid = j; // creating node and giving j value
                start = ptr_graphdetails->graphptr[i];
                if (start == NULL)
                {
                    start = newnode;
                }
                else
                {
                    dstart = start;
                    while (dstart->link != NULL)
                    {
                        dstart = dstart->link;
                    }
                    dstart->link = newnode;
                }
                printf("%d", ptr_graphdetails->graphptr[i]->vid);
                ptr_graphdetails->edges++;
            }
        }
    }
}

void BFS(int src, g_details *ptr_graphdetails, int *visited, int n)
{
    bfst(src, ptr_graphdetails, visited, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                bfs(ptr_graphdetails, visited, n);
            }
        }
    }
}

void bfst(int src, g_details *ptr_graphdetails, int *visited, int n)
{
    queue *pq;
    int delvertex;
    int n; // to count no of vertices
    graphnode *start;
    pq = malloc(sizeof(queue));
    n = ptr_graphdetails->vertices;
    initq(pq, n);
    visited[src] = 1;
    enqueue(pq, src);
    int vindex; // stores vertex id
    while (!isempty(pq))
    {
        delvertex = dequeue(pq);
        start = ptr_graphdetails->graphptr[delvertex];
        while (start != NULL)
        {
            vindex = start->vid;
            if (visited[vindex] == 0)
            {
                visited[vindex] = 1;
                printf("%d", vindex);
                enqueue(pq, vindex);
            }
            start = start->link;
        }
    }
}

int main()
{
    int vertices;
    int *visited;
    int src;
    g_details *ptr_graphdetails = malloc(sizeof(g_details));
    printf("Enter number of vertices :");
    scanf("%d", &vertices);
    visited = malloc(sizeof(int) * vertices);
    ptr_graphdetails->vertices = vertices;
    ptr_graphdetails->edges = 0;
    ptr_graphdetails->graphptr = NULL;
    for (int i = 0; i < ptr_graphdetails->vertices; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the source :\n");
    scanf("%d", &src);
    allocgraph(ptr_graphdetails);
    readgraph(ptr_graphdetails);
    display(ptr_graphdetails);
}

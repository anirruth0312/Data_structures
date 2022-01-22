#include <stdio.h>
#include <stdlib.h>

int **creatematrix(int n)
{
    int **adjmat; // allocating matrix memory
    adjmat = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        adjmat[i] = malloc(sizeof(int) * n);
    }
    return adjmat;
}

void dfs(int source, int **adjmat, int *visited, int n, int flag) // visited denotes the elements that are visited in the array
{
    int i;
    visited[source] = 1; // source gets visited
    if (flag == 0)
        printf("%d\t", source);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && adjmat[source][i] == 1) // finding neighbour
        {
            dfs(i, adjmat, visited, n, 0);
        }
    }
}

void connectivity(int start, int **adjmat, int *visited, int n, int dest)
{
    int flag = 0;
    dfs(start, adjmat, visited, n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[dest] == 1)
        {
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("\nConnectivitity is there \n");
    }
    else
        printf("\nNo Connectivity");
}

void DFS(int source, int **adjmat, int *visited, int n, int flag)
{
    int count = 1;
    int i;
    dfs(source, adjmat, visited, n, 0);
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0) // checking for not visited elements
        {
            dfs(i, adjmat, visited, n, 0);
            count++;
        }
    }
    printf("\nNo of components is %d", count);
}
int main()
{
    int **adjmat;
    int n, source;
    printf("Enter the size of the matrix :");
    scanf("%d", &n);
    int visited[n];
    adjmat = creatematrix(n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the elements of the adjacency matrix :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjmat[i][j]);
        }
    }
    printf("\nEnter source :");
    scanf("%d", &source);
    DFS(source, adjmat, visited, n, 0);
    printf("\nEnter the two elements to check connectivity \n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    connectivity(a, adjmat, visited, n, b);
}
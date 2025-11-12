#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V;

void DFS(int u)
{
    visited[u] = true;
    printf("%d ", u);

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v] && !visited[v])
        {
            DFS(v);
        }
    }
}

int main()
{
    int E, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V;

void DFS(int u)
{
    visited[u] = true;
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
    int E, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFS(0); // start from vertex 0

    bool connected = true;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            connected = false;
            break;
        }
    }

    if (connected)
        printf("Graph is connected\n");
    else
        printf("Graph is NOT connected\n");

    return 0;
}
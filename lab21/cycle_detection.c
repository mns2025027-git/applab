#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V;

bool cycleUtil(int u, int parent)
{
    visited[u] = true;

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v])
        {
            if (!visited[v])
            {
                if (cycleUtil(v, u))
                    return true;
            }
            else if (v != parent)
            {
                return true; // found a cycle
            }
        }
    }
    return false;
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

    bool cycle = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (cycleUtil(i, -1))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        printf("Graph contains a cycle\n");
    else
        printf("Graph does NOT contain a cycle\n");

    return 0;
}
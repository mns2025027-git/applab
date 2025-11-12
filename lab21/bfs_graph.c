#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int V;

void BFS(int start)
{
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] && !visited[v])
            {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
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

    BFS(start);
    return 0;
}
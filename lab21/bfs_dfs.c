#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V;

// ---------- BFS using Queue ----------
void BFS(int start)
{
    bool seen[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;

    seen[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] && !seen[v])
            {
                seen[v] = true;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

// ---------- DFS using Stack ----------
void DFS(int start)
{
    bool seen[MAX] = {false};
    int stack[MAX], top = -1;

    seen[start] = true;
    stack[++top] = start;

    printf("DFS Traversal: ");
    while (top >= 0)
    {
        int u = stack[top--];
        printf("%d ", u);

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] && !seen[v])
            {
                seen[v] = true;
                stack[++top] = v;
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
    DFS(start);

    return 0;
}
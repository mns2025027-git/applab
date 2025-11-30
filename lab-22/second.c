/*
2. Write a C program that reads an adjacency matrix of a connected weighted graph and
generates its MST using Prim’s Algorithm. The program must print the edges selected at
each step and the total MST weight.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[MAX][MAX], int V)
{
    int parent[V]; // Store MST
    int key[V];    // Key values
    int mstSet[V]; // Included in MST?

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;     // Start from vertex 0
    parent[0] = -1; // First node is root

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    printf("\nEdges in MST (Prim):\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total MST weight = %d\n", totalWeight);
}

int main()
{
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);
    return 0;
}

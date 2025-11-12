#include <stdio.h>

void createAdjMatrix(int edges[][2], int adjMatrix[][5], int e)
{
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}
int main()
{
    int adjMatrix[5][5] = {0};
    int edges[6][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};
    int e = sizeof(edges) / sizeof(edges[0]);
    createAdjMatrix(edges, adjMatrix, e);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
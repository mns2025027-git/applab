#include <stdio.h>
#include <stdlib.h>

#define Max 100

int Color[Max];

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

struct Graph
{
    int numVertices;
    node *adjList[Max];
};

node *createNode(int v)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int v)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = v;

    for (int i = 0; i < v; i++)
    {
        graph->adjList[i] = NULL;
        Color[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *g, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

int dfsColoring(struct Graph *g, int v, int color)
{
    Color[v] = color;
    int neighbourColor = (color == 1) ? 2 : 1;

    node *temp = g->adjList[v];

    while (temp != NULL)
    {
        int neighbour = temp->vertex;

        if (Color[neighbour] == 0)
        {
            if (dfsColoring(g, neighbour, neighbourColor) == 0)
                return 0;
        }
        else if (Color[neighbour] == color)
        {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main()
{
    int vertices = 4;
    struct Graph *g = createGraph(vertices);

    // Example: A Square (0-1-2-3-0)
    // This IS 2-colorable (0=Red, 1=Blue, 2=Red, 3=Blue)
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 3, 0);

    if (dfsColoring(g, 0, 1) == 0)
        printf("This is graph can't be painted by two colors!! \n");
    else
        printf("This is graph can be painted by two colors!! \n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define Max 100

int stack[Max];
int top = -1;

typedef struct Node
{
    int vertex;
    struct Node *next;

} node;

typedef struct Graph
{
    int numVertices;
    node *adjList[Max];
    int visited[Max];
} graph;

node *createNode(int v)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(int vertices)
{
    graph *newGraph = malloc(sizeof(graph));
    newGraph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        newGraph->adjList[i] = NULL;
        newGraph->visited[i] = 0;
    }
    return newGraph;
}

void addEdge(graph *Graph, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = Graph->adjList[src];
    Graph->adjList[src] = newNode;
}

void push(int n)
{
    if (top < Max)
        stack[++top] = n;
    else
        printf("Stack is full\n");
}

void dfs(graph *Graph, int vertex)
{
    Graph->visited[vertex] = 1;

    node *temp = Graph->adjList[vertex];

    while (temp != NULL)
    {
        int neighbour = temp->vertex;

        if (Graph->visited[neighbour] == 0)
            dfs(Graph, neighbour);
        temp = temp->next;
    }
    push(vertex);
}

void topologicalSort(graph *Graph)
{

    for (int i = 0; i < Graph->numVertices; i++)
    {
        if (Graph->visited[i] == 0)
            dfs(Graph, i);
    }

    printf("Topological Sort for this Graph is: \n");

    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main()
{
    int vertices = 6;
    graph *graph = createGraph(vertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);
    return 0;
}
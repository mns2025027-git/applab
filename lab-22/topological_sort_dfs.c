#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// --- 1. ADJACENCY LIST STRUCTURES ---

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX];
    int visited[MAX]; // To keep track of visited nodes
} Graph;

// --- 2. HELPERS ---

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // 0 = Not Visited
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// --- 3. THE DFS ALGORITHM ---

// The Stack (Simple global array for demo)
int stack[MAX];
int top = -1;

void push(int v)
{
    stack[++top] = v;
}

// The Recursive DFS Function
void dfs(Graph *graph, int vertex)
{
    // 1. Mark current node as visited
    graph->visited[vertex] = 1;

    // 2. Visit all adjacent vertices (neighbors)
    Node *temp = graph->adjLists[vertex];
    while (temp != NULL)
    {
        int neighbor = temp->vertex;

        // Only go there if we haven't visited it yet
        if (graph->visited[neighbor] == 0)
        {
            dfs(graph, neighbor);
        }

        temp = temp->next;
    }

    // 3. CRITICAL STEP: Push to stack AFTER visiting all children
    // This node is "done" processing.
    push(vertex);
}

// Wrapper function to handle disconnected graphs
void topologicalSort(Graph *graph)
{
    // Call DFS for every unvisited vertex
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->visited[i] == 0)
        {
            dfs(graph, i);
        }
    }

    // 4. Print the Stack (Top to Bottom)
    printf("Topological Sort (DFS): ");
    while (top >= 0)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// --- 4. MAIN ---

int main()
{
    int vertices = 6;
    Graph *graph = createGraph(vertices);

    // Same example edges: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
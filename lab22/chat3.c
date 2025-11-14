#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dest;
    struct node *next;
} Node;

typedef struct graph
{
    int V;
    Node **adj; // array of adjacency list heads
} Graph;

// Create graph
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (Node **)malloc(V * sizeof(Node *));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Add undirected edge u-v
void addEdge(Graph *graph, int u, int v)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->dest = v;
    node->next = graph->adj[u];
    graph->adj[u] = node;

    node = (Node *)malloc(sizeof(Node));
    node->dest = u;
    node->next = graph->adj[v];
    graph->adj[v] = node;
}

// Check bipartite using BFS
int isBipartite(Graph *graph)
{
    int V = graph->V;
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    // Simple queue using linked list
    Node *queue = NULL, *rear = NULL;

    for (int start = 0; start < V; start++)
    {
        if (color[start] == -1)
        {
            color[start] = 0;

            Node *node = (Node *)malloc(sizeof(Node));
            node->dest = start;
            node->next = NULL;
            queue = rear = node;

            while (queue)
            {
                int u = queue->dest;
                queue = queue->next;

                Node *temp = graph->adj[u];
                while (temp)
                {
                    if (color[temp->dest] == -1)
                    {
                        color[temp->dest] = 1 - color[u];
                        Node *newNode = (Node *)malloc(sizeof(Node));
                        newNode->dest = temp->dest;
                        newNode->next = NULL;
                        if (!queue)
                            queue = rear = newNode;
                        else
                        {
                            rear->next = newNode;
                            rear = newNode;
                        }
                    }
                    else if (color[temp->dest] == color[u])
                    {
                        return 0; // conflict
                    }
                    temp = temp->next;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Graph *graph = createGraph(V);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isBipartite(graph))
        printf("Graph is 2-colorable (Bipartite)\n");
    else
        printf("Graph is NOT 2-colorable\n");

    return 0;
}

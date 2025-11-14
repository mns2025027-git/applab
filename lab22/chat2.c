#include <stdio.h>
#include <stdlib.h>

// Linked list node for adjacency
struct AdjNode
{
    int dest;
    struct AdjNode *next;
};

// Graph structure
struct Graph
{
    int V;
    struct AdjNode **adj;
};

// Create graph
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct AdjNode **)malloc(V * sizeof(struct AdjNode *));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Add edge u->v
void addEdge(struct Graph *graph, int u, int v)
{
    struct AdjNode *node = (struct AdjNode *)malloc(sizeof(struct AdjNode));
    node->dest = v;
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

// Topological Sort
void topoSort(struct Graph *graph)
{
    int V = graph->V;
    int indeg[V];
    for (int i = 0; i < V; i++)
        indeg[i] = 0;

    // Compute indegree
    for (int u = 0; u < V; u++)
    {
        struct AdjNode *temp = graph->adj[u];
        while (temp)
        {
            indeg[temp->dest]++;
            temp = temp->next;
        }
    }

    // Queue using linked list
    struct AdjNode *queue = NULL, *rear = NULL;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            struct AdjNode *node = (struct AdjNode *)malloc(sizeof(struct AdjNode));
            node->dest = i;
            node->next = NULL;
            if (!queue)
                queue = rear = node;
            else
            {
                rear->next = node;
                rear = node;
            }
        }
    }

    printf("Topological Order: ");
    while (queue)
    {
        int u = queue->dest;
        printf("%d ", u);
        queue = queue->next;

        struct AdjNode *temp = graph->adj[u];
        while (temp)
        {
            indeg[temp->dest]--;
            if (indeg[temp->dest] == 0)
            {
                struct AdjNode *node = (struct AdjNode *)malloc(sizeof(struct AdjNode));
                node->dest = temp->dest;
                node->next = NULL;
                if (!queue)
                    queue = rear = node;
                else
                {
                    rear->next = node;
                    rear = node;
                }
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Driver
int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Graph *graph = createGraph(V);

    printf("Enter edges (u v) meaning u->v:\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topoSort(graph);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node* next;
} node;

node* createNode(int key)
{
    node* newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void createAdjList(node* adjList[], int u, int v)
{
    node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

int main()
{
    int u, v, edges, vertices;
    printf("Enter the value of edges and vertices: ");
    scanf("%d%d", &edges, &vertices);

    node* adjList[vertices];

    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
    }

    printf("Enter the values (u,v):\n ");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);
        createAdjList(adjList, u, v);
    }

    for (int i = 0; i < vertices; i++)
    {
        printf("Vertex %d is connected to: ", i);
        node* temp = adjList[i];
        if (!temp)
        {
            printf("None");
        }
        else
        {
            while (temp)
            {
                printf("%d", temp->key);
                temp = temp->next;
                if (temp) printf(", ");  // add commas between neighbors
            }
        }
        printf("\n");
    }

    return 0;
}
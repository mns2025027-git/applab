#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n, val;
    printf("Number of node? ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        printf("Value of %d node: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = malloc(sizeof(struct Node));

        newNode->data = val;
        newNode->next = NULL;

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* temp = head;

    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("Null");

    temp = head;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
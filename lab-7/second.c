#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top = NULL;

void push()
{
    Node *newNode = malloc(sizeof(Node));

    int val;
    printf("Value?");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("-1");
        return;
    }
    Node *temp = top;
    top = top->next;

    printf("Popped %d", temp->data);
    free(temp);
}

void seek()
{
    if (top == NULL)
    {
        printf("-1");
        return;
    }
    printf("Top value %d", top->data);
}

int main()
{
    int n;
    do
    {
        printf("\n---------------");
        printf("\n1.Push ?");
        printf("\n2.Pop ?");
        printf("\n3.Seek ?");
        printf("\n4.Exit\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            seek();
            break;
        }
    } while (n != 4);

    return 0;
}
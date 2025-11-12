#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} Node;

Node *front = NULL, *rear = NULL;

void enq()
{
    Node *newNode = malloc(sizeof(Node));

    int val;
    printf("Value? ");
    scanf("%d", &val);

    newNode->data = val;

    if (front == NULL)
    {
        front = rear = newNode;
        newNode->next = newNode->prev = newNode;
        return;
    }

    newNode->next = front;
    newNode->prev = rear;
    rear->next = newNode;
    front->prev = newNode;
    rear = newNode;
}

void deq()
{
    if (front == NULL)
    {
        printf("Empty!");
        return;
    }

    Node *temp = front;

    if (front == rear)
    {
        free(temp);
        front = rear = NULL;
        return;
    }

    front = front->next;
    front->prev = rear;
    rear->next = front;

    printf("Front value is %d", temp->data);
    free(temp);
}

void isempty()
{
    if (front == NULL)
        printf("YUP!");
    else
        printf("NOPE!");
}

void traverse()
{
    if (front == NULL)
        printf("Empty!");
    else
    {
        Node *temp = front;
        do
        {
            printf("[%d] ", temp->data);
            temp = temp->next;
        } while ((temp) != front);
    }
}

int main()
{
    int n;
    do
    {
        printf("\n---------------");
        printf("\n1.Enqueue?");
        printf("\n2.Dequeue?");

        printf("\n3.Empty?");
        printf("\n4.Traverse?");
        printf("\n5.Exit?\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;

        case 3:
            isempty();
            break;
        case 4:
            traverse();
            break;
        }
    } while (n != 5);

    return 0;
}

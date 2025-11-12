#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void get_element(Node **head)
{
    int val;
    printf("Enter element: ");
    scanf("%d", &val);

    Node *newNode = malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    if (!*head)
    {
        *head = newNode;
        return;
    }

    Node *p = *head;

    while (p->next)
    {
        if (p->next->data > val)
            break;
        if (p->next->data <= val)
            p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;
}

void show_list(Node **head)
{
    Node *p = *head;

    if (!*head)
    {
        printf("NULL");
        return;
    }

    while (p)
    {

        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    Node *head = NULL;
    do
    {

        printf("\n------Menu-------\n");
        printf("1.Enter element\n");
        printf("2.Show List\n");

        printf("8.Exit\n");

        scanf("%d", &n);

        switch (n)
        {
        case 1:
            get_element(&head);
            break;
        case 2:
            show_list(&head);
            break;
        }
    } while (n != 8);

    return 0;
}
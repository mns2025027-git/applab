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
        p = p->next;
    }

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

void remove_duplicate(Node **head)
{
    if (!*head)
        return;

    Node *curr = *head;

    while (curr)
    {
        Node *Next = curr;
        while (Next->next)
        {
            if (Next->next->data == curr->data)
            {
                Node *temp = Next->next;
                Next->next = Next->next->next;
                free(temp);
            }
            else
            {
                Next = Next->next;
            }
        }
        curr = curr->next;
    }
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
        printf("3.Remove Duplicate\n");

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
        case 3:
            remove_duplicate(&head);
            break;
        }
    } while (n != 8);

    return 0;
}
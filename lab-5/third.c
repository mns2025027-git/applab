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
        if (p->next->data > val) break;
        if (p->next->data <= val) p = p->next;
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

void skip_and_delete(Node **head)
{
    if (!*head) return;

    int n, m;
    printf("Enter the value of m and n: ");
    scanf("%d%d", &m, &n);

    Node *p = *head;

    while (p)
    {
        int mcount = m, ncount = n;
        while (mcount > 1 && p != NULL)
        {
            p = p->next;
            mcount--;
        }
        if (!p) return;

        Node *curr = p->next;
        while (ncount > 0 && curr != NULL)
        {
            Node *todelete = curr;
            curr = curr->next;
            free(todelete);
            ncount--;
        }
        p->next = curr;
        p = curr;

        if (!p) return;
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
        printf("3.Have fun\n");

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
                skip_and_delete(&head);
                break;
        }
    } while (n != 8);

    return 0;
}
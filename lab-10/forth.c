/*
4. Implement radix sort algorithm using singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>

#define BASE 10

struct Node
{
    int data;
    struct Node* next;
};

// Insert node at end
void insert(struct Node** head, int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Get max value in list
int getMax(struct Node* head)
{
    int max = head->data;
    while (head)
    {
        if (head->data > max) max = head->data;
        head = head->next;
    }
    return max;
}

// Radix sort
void radixSort(struct Node** head)
{
    struct Node *buckets[BASE] = {NULL}, *tails[BASE] = {NULL};
    int max = getMax(*head), exp = 1;

    while (max / exp > 0)
    {
        struct Node* curr = *head;
        while (curr)
        {
            int index = (curr->data / exp) % BASE;
            if (!buckets[index])
            {
                buckets[index] = tails[index] = curr;
            }
            else
            {
                tails[index]->next = curr;
                tails[index] = curr;
            }
            curr = curr->next;
        }

        *head = NULL;
        struct Node* last = NULL;
        for (int i = 0; i < BASE; i++)
        {
            if (buckets[i])
            {
                if (!*head)
                {
                    *head = buckets[i];
                    last = tails[i];
                }
                else
                {
                    last->next = buckets[i];
                    last = tails[i];
                }
                buckets[i] = tails[i] = NULL;
            }
        }
        last->next = NULL;
        exp *= BASE;
    }
}

// Print list
void printList(struct Node* head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, value;
    struct Node* head = NULL;

    printf("Number of elements? ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(&head, value);
    }

    radixSort(&head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}

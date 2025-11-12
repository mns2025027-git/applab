/*
2. Implement bubble sort algorithm using singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
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
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// Bubble sort on linked list
void bubbleSort(struct Node* head)
{
    if (!head) return;

    int swapped;
    struct Node* ptr;
    struct Node* lptr = NULL;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->data > ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Print the linked list
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

    bubbleSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}

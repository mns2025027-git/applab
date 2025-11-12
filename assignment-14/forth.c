#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

Node *root = NULL;

Node *create(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (!root) return create(data);
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int findLargest(Node *root)
{
    if (!root) return -1;
    while (root->right != NULL) root = root->right;
    return root->data;
}

int main()
{
    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    for (int i = 0; i < 9; i++) root = insert(root, arr[i]);

    int largest = findLargest(root);
    printf("Largest element in BST is: %d\n", largest);

    return 0;
}

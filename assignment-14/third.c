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

int findLevel(Node *root, int key, int level)
{
    if (!root) return -1;
    if (root->data == key) return level;
    if (key < root->data)
        return findLevel(root->left, key, level + 1);
    else
        return findLevel(root->right, key, level + 1);
}

int main()
{
    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    for (int i = 0; i < 9; i++) root = insert(root, arr[i]);

    int key;
    printf("Enter element to find its level: ");
    scanf("%d", &key);

    int level = findLevel(root, key, 0);
    if (level != -1)
        printf("Element %d is at level %d\n", key, level);
    else
        printf("Element not found in BST\n");

    return 0;
}

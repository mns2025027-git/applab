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
    newNode->right = newNode->left = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (!root)
        return create(data);
    if (root->data >= data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
};

void preorder(Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int choice;

    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};

    for (int i = 0; i < 9; i++)
    {
        root = insert(root, arr[i]);
    }

    do
    {
        printf("\n-----------------------");
        printf("\n1.Preorder?");
        printf("\n2.Inorder?");
        printf("\n3.Postorder?");
        printf("\n4.Exit?");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        }
    } while (choice != 4);
    return 0;
}
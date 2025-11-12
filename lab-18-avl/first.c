#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
    int height;
} node;

node* root = NULL;

node* createNode(int key)
{
    node* newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}
int getHeight(node* n)
{
    return n ? n->height : 0;
}

int getBalance(node* root)
{
    if (!root) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

node* rightRotate(node* root)
{
    node* x = root->left;
    node* temp = x->right;
    x->right = root;
    root->left = temp;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
node* leftRotate(node* root)
{
    node* x = root->right;
    node* temp = x->left;
    x->left = root;
    root->right = temp;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

node* insertNode(node* root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (root->key > key)
        root->left = insertNode(root->left, key);
    else if (root->key < key)
        root->right = insertNode(root->right, key);
    else
        return root;  // if the key and the root->key are equal.

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
    {
        // LL
        return rightRotate(root);
    }
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(node* root)
{
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
int main()
{
    int arr[] = {50, 39, 2, 80, 66, 3, 64, 75, 12, 10, 90, 39};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, arr[i]);
    }
    inorder(root);
    return 0;
}
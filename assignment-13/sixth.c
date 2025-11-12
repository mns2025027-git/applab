#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left, *right;
} Node;

Node* createNode(char data)
{
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int isStrictBinaryTree(Node* root)
{
    if (!root) return 1;
    if (!root->left && !root->right) return 1;
    if (root->left && root->right)
        return isStrictBinaryTree(root->left) && isStrictBinaryTree(root->right);
    return 0;
}

int main()
{
    Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');

    if (isStrictBinaryTree(root))
        printf("The tree is a Strict Binary Tree\n");
    else
        printf("The tree is NOT a Strict Binary Tree\n");

    return 0;
}

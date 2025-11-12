#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left, *right;
} Node;

Node *createNode(char data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}

void mirror(Node *root)
{
    if (!root) return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(Node *root)
{
    if (!root) return;
    if (root->right || root->left) printf("[");
    inorder(root->left);
    printf(" %c ", root->data);
    inorder(root->right);
    if (root->right || root->left) printf("]");
}

int main()
{
    Node *mult1 = createNode('*');
    Node *mult2 = createNode('*');
    Node *add1 = createNode('+');
    Node *add2 = createNode('+');
    Node *sub = createNode('-');
    Node *div = createNode('/');

    Node *two1 = createNode('2');
    Node *two2 = createNode('2');
    Node *three = createNode('3');
    Node *four = createNode('4');
    Node *five = createNode('5');
    Node *six = createNode('6');
    Node *eight = createNode('8');

    mult1->left = three;
    mult1->right = four;
    div->left = six;
    div->right = two1;
    add1->left = mult1;
    add1->right = div;
    add2->left = eight;
    add2->right = two2;
    sub->left = add1;
    sub->right = add2;
    mult2->left = five;
    mult2->right = sub;

    inorder(mult2);
    mirror(mult2);
    printf("\n");
    inorder(mult2);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int internal = 0, external = 0, total = 0;

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

void countNodes(Node *root)
{
    if (!root) return;

    total++;

    if (root->left == NULL && root->right == NULL)
        external++;
    else
        internal++;
    countNodes(root->left);
    countNodes(root->right);
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

    countNodes(mult2);

    printf("\nNumber of internal nodes: %d ", internal);
    printf("\nNumber of external nodes: %d ", external);
    printf("\nNumber of total nodes: %d ", total);
    return 0;
}

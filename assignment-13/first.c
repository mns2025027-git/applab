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

Node *queue[100];
int front = 0, rear = 0;

void levelorder(Node *root)
{
    if (!root)
        return;

    front = rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];

        printf("%c", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

int findlevel(Node *root, char val, int level)
{
    if (!root)
        return -1;
    if (val == root->data)
        return level;

    int leftlevel = findlevel(root->left, val, level + 1);
    if (leftlevel != -1)
        return leftlevel;
    return findlevel(root->right, val, level + 1);
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

    char val;
    printf("Enter the value to search: ", &val);
    scanf("%c", &val);

    printf("Your value %c exists at the level %d", val, findlevel(mult2, val, 0));
    return 0;
}

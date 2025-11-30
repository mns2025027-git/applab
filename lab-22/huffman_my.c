#include <stdio.h>
#include <stdlib.h>

#define MaxHeight 100

typedef struct Node
{
    char data;
    int freq;
    struct Node *left, *right;
} node;

node *createNode(char c, int freq)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = c;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int compare(const void *a, const void *b)
{
    const node *x = (node *)a;
    const node *y = (node *)b;

    return (x->freq - y->freq);
}

node *buildHuffmanTree(node nodes[], int size)
{

    while (size > 1)
    {
        qsort(nodes, size, sizeof(nodes[0]), compare);

        node *left = createNode(nodes[0].data, nodes[0].freq);
        left->left = nodes[0].left;
        left->right = nodes[0].right;

        node *right = createNode(nodes[1].data, nodes[1].freq);
        right->left = nodes[1].left;
        right->right = nodes[1].right;

        node *top = createNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        nodes[0] = *top;
        nodes[1] = nodes[size - 1];

        size--;
    }

    return &nodes[0];
}

void printCodes(node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right)
    {
        if (root->data != ' ')
            printf("%c : ", root->data);

        for (int i = 0; i < top; i++)
        {

            if (root->data == ' ')
                continue;
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    char str[1000];
    printf("Enter the string: ");
    scanf("%[^\n]", str);

    int freq[256] = {0};
    int size = 0;

    for (int i = 0; str[i]; i++)
    {
        freq[(unsigned int)str[i]]++;
    }

    node Nodes[256];

    for (int i = 0; i < 256; i++)
    {
        if (freq[i])
        {
            Nodes[size].data = (char)i;
            Nodes[size].freq = freq[i];
            Nodes[size].left = Nodes[size].right = NULL;
            size++;
        }
    }

    if (size < 1)
    {

        printf("Nothing in here to print!!\n");
        return 0;
    }

    node *tree = buildHuffmanTree(Nodes, size);
    int height[MaxHeight];
    printCodes(tree, height, 0);

    return 0;
}
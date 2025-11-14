#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for Huffman tree
struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

// Create new node
struct Node *newNode(char ch, int freq)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Print Huffman codes
void printCodes(struct Node *root, char *code, int depth)
{
    if (!root)
        return;

    // Leaf node → print character and code
    if (!root->left && !root->right)
    {
        code[depth] = '\0';
        printf("%c: %s\n", root->ch, code);
        return;
    }

    code[depth] = '0';
    printCodes(root->left, code, depth + 1);

    code[depth] = '1';
    printCodes(root->right, code, depth + 1);
}

// Build Huffman tree (simple version using sorting)
struct Node *buildHuffmanTree(char data[], int freq[], int n)
{
    struct Node *nodes[256]; // store pointers to nodes
    for (int i = 0; i < n; i++)
        nodes[i] = newNode(data[i], freq[i]);

    while (n > 1)
    {
        // Find two smallest frequencies
        int min1 = 0, min2 = 1;
        if (nodes[min2]->freq < nodes[min1]->freq)
        {
            int tmp = min1;
            min1 = min2;
            min2 = tmp;
        }

        for (int i = 2; i < n; i++)
        {
            if (nodes[i]->freq < nodes[min1]->freq)
            {
                min2 = min1;
                min1 = i;
            }
            else if (nodes[i]->freq < nodes[min2]->freq)
                min2 = i;
        }

        // Create new internal node
        struct Node *left = nodes[min1];
        struct Node *right = nodes[min2];
        struct Node *parent = newNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        // Replace min1 with parent, remove min2
        nodes[min1] = parent;
        nodes[min2] = nodes[n - 1];
        n--;
    }
    return nodes[0]; // return the actual root
}

int main()
{
    char str[1000]; // buffer for input string
    printf("Enter a string: ");
    scanf("%s", str); // read input (no spaces)

    int freq[256] = {0};

    // Count frequency
    for (int i = 0; str[i]; i++)
        freq[(unsigned char)str[i]]++;

    // Collect unique chars
    char data[256];
    int f[256], n = 0;
    for (int i = 0; i < 256; i++)
    {
        if (freq[i])
        {
            data[n] = i;
            f[n] = freq[i];
            n++;
        }
    }

    struct Node *root = buildHuffmanTree(data, f, n);
    char code[100];
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    return 0;
}

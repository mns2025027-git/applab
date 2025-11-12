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

int search(char inorder[], int start, int end, char value)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == value) return i;
    return -1;
}

Node* buildTree(char inorder[], char preorder[], int inStart, int inEnd, int* preIndex)
{
    if (inStart > inEnd) return NULL;
    char curr = preorder[*preIndex];
    (*preIndex)++;
    Node* node = createNode(curr);
    if (inStart == inEnd) return node;
    int inIndex = search(inorder, inStart, inEnd, curr);
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);
    return node;
}

void printPostorder(Node* root)
{
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%c ", root->data);
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    char preorder[n], inorder[n];
    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++) scanf(" %c", &preorder[i]);
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) scanf(" %c", &inorder[i]);

    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    return 0;
}

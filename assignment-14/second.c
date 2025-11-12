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
    if (!root) return create(data);
    if (root->data >= data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
};

Node *search(Node *root, int key)
{
    if (!root || root->data == key) return root;
    if (root->data > key) return search(root->left, key);
    return search(root->right, key);
}

Node *minNode(Node *root)
{
    if (root->left == NULL) return root;

    return minNode(root->left);
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node found
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        Node *temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preorder(Node *root)
{
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root) return;
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
        printf("\n4.Minimum?");
        printf("\n5.Search?");
        printf("\n6.Delete?");
        printf("\n8.Exit?");

        scanf("%d", &choice);
        Node *node;
        int key;
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
            case 4:
                node = minNode(root);
                if (node)
                    printf("Minimum value is %d", node->data);
                else
                    printf("Value not found!");
                break;
            case 5:

                printf("\nKey? ");
                scanf("%d", &key);
                node = search(root, key);
                if (node)
                    printf("Value found!");
                else
                    printf("Value not found!");
                break;
            case 6:

                printf("\nValue to delete: ");
                scanf("%d", &key);
                node = deleteNode(root, key);
                if (node)
                    printf("Node deleted");
                else
                    printf("Node not found!");
                break;
        }
    } while (choice != 8);
    return 0;
}
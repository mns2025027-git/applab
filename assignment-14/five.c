#include <stdio.h>

#define MAX 100
int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertHeap(int value)
{
    heap[++size] = value;
    int i = size;
    while (i > 1 && heap[i / 2] < heap[i])
    {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void inorderHeap(int i)
{
    if (i <= size)
    {
        inorderHeap(2 * i);
        printf("%d ", heap[i]);
        inorderHeap(2 * i + 1);
    }
}

void preorderHeap(int i)
{
    if (i <= size)
    {
        printf("%d ", heap[i]);
        preorderHeap(2 * i);
        preorderHeap(2 * i + 1);
    }
}

void postorderHeap(int i)
{
    if (i <= size)
    {
        postorderHeap(2 * i);
        postorderHeap(2 * i + 1);
        printf("%d ", heap[i]);
    }
}

int main()
{
    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) insertHeap(arr[i]);

    printf("Inorder traversal of Heap: ");
    inorderHeap(1);
    printf("\n");

    printf("Preorder traversal of Heap: ");
    preorderHeap(1);
    printf("\n");

    printf("Postorder traversal of Heap: ");
    postorderHeap(1);
    printf("\n");

    return 0;
}

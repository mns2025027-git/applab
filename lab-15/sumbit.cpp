// 1. Create Min-Heap tree for
// 50, 10, 20, 30, 5, 90, 80, 100, 85.
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int a[], int n, int i)
{
    int s = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] < a[s]) s = l;
    if (r < n && a[r] < a[s]) s = r;
    if (s != i)
    {
        swap(&a[i], &a[s]);
        heapify(a, n, s);
    }
}
void buildMinHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
}
int main()
{
    int a[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(a) / sizeof(a[0]);
    buildMinHeap(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

// 2. Create Max-Heap for the data given in program-1.
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int a[], int n, int i)
{
    int m = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[m]) m = l;
    if (r < n && a[r] > a[m]) m = r;
    if (m != i)
    {
        swap(&a[i], &a[m]);
        heapify(a, n, m);
    }
}
void buildMaxHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
}
int main()
{
    int a[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(a) / sizeof(a[0]);
    buildMaxHeap(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

// 3. Perform Heap sort using Min-Heap created in program-1.
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int a[], int n, int i)
{
    int s = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] < a[s]) s = l;
    if (r < n && a[r] < a[s]) s = r;
    if (s != i)
    {
        swap(&a[i], &a[s]);
        heapify(a, n, s);
    }
}
void buildMinHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
}
void heapSort(int a[], int n)
{
    buildMinHeap(a, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
int main()
{
    int a[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(a) / sizeof(a[0]);
    heapSort(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

// 4. Using Max-Heap created in program-2, write a C program to find the Kth minimum
// element.
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int a[], int n, int i)
{
    int m = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[m]) m = l;
    if (r < n && a[r] > a[m]) m = r;
    if (m != i)
    {
        swap(&a[i], &a[m]);
        heapify(a, n, m);
    }
}
void buildMaxHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
}
int kthMin(int a[], int n, int k)
{
    int *b = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) b[i] = a[i];
    int size = n;
    for (int i = 0; i < k - 1; i++)
    {
        swap(&b[0], &b[size - 1]);
        size--;
        heapify(b, size, 0);
    }
    int res = b[0];
    free(b);
    return res;
}
int main()
{
    int a[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(a) / sizeof(a[0]);
    buildMaxHeap(a, n);
    int k = 3;
    printf("%d", kthMin(a, n, k));
    return 0;
}

// 5. Write a C program to convert the given BST to Max-Heap.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int d;
    struct Node *l, *r;
};
struct Node *newNode(int d)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->d = d;
    n->l = n->r = NULL;
    return n;
}
struct Node *insert(struct Node *r, int d)
{
    if (!r) return newNode(d);
    if (d < r->d)
        r->l = insert(r->l, d);
    else
        r->r = insert(r->r, d);
    return r;
}
void inorder(struct Node *r, int arr[], int *idx)
{
    if (!r) return;
    inorder(r->l, arr, idx);
    arr[(*idx)++] = r->d;
    inorder(r->r, arr, idx);
}
void bstToMaxHeapUtil(struct Node *r, int arr[], int *idx)
{
    if (!r) return;
    bstToMaxHeapUtil(r->l, arr, idx);
    bstToMaxHeapUtil(r->r, arr, idx);
    r->d = arr[(*idx)++];
}
void bstToMaxHeap(struct Node *r, int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    int i = 0;
    inorder(r, arr, &i);
    i = 0;
    bstToMaxHeapUtil(r, arr, &i);
    free(arr);
}
void preorder(struct Node *r)
{
    if (!r) return;
    printf("%d ", r->d);
    preorder(r->l);
    preorder(r->r);
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 15);
    bstToMaxHeap(root, 6);
    preorder(root);
    return 0;
}

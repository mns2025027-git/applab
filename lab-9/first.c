// 1. Take a matrix as an input from the user such that the number of zeros are more than non-zero
// elements. Store and Print it. Now store this matrix as a sparse matrix using a linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int r, c, v;
    struct node* next;
};
struct node* create(int r, int c, int v)
{
    struct node* t = malloc(sizeof(struct node));
    t->r = r;
    t->c = c;
    t->v = v;
    t->next = NULL;
    return t;
}
void display(struct node* h)
{
    while (h)
    {
        printf("%d %d %d\n", h->r, h->c, h->v);
        h = h->next;
    }
}
int main()
{
    int m, n, i, j;
    printf("Enter rows and cols: ");
    scanf("%d%d", &m, &n);
    int a[m][n];
    printf("Enter matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
    printf("Matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    struct node *head = NULL, *last = NULL;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != 0)
            {
                struct node* t = create(i, j, a[i][j]);
                if (!head)
                    head = last = t;
                else
                {
                    last->next = t;
                    last = t;
                }
            }
    printf("Sparse form:\n");
    display(head);
    return 0;
}
// 3. Create a program to add two sparse matrices. Assuming that you have created two sparse
// matrices using linked lists as in program 1.
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
void insert(struct node** h, int r, int c, int v)
{
    if (v == 0) return;
    struct node *p = *h, *prev = NULL;
    while (p && (p->r < r || (p->r == r && p->c < c)))
    {
        prev = p;
        p = p->next;
    }
    if (p && p->r == r && p->c == c)
    {
        p->v += v;
        if (p->v == 0)
        {
            if (prev)
                prev->next = p->next;
            else
                *h = p->next;
            free(p);
        }
        return;
    }
    struct node* t = create(r, c, v);
    t->next = p;
    if (prev)
        prev->next = t;
    else
        *h = t;
}
struct node* add(struct node* a, struct node* b)
{
    struct node* res = NULL;
    while (a)
    {
        insert(&res, a->r, a->c, a->v);
        a = a->next;
    }
    while (b)
    {
        insert(&res, b->r, b->c, b->v);
        b = b->next;
    }
    return res;
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
    int n, i, r, c, v;
    struct node *a = NULL, *b = NULL;
    printf("Enter number of elements in first matrix: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &r, &c, &v);
        insert(&a, r, c, v);
    }
    printf("Enter number of elements in second matrix: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &r, &c, &v);
        insert(&b, r, c, v);
    }
    struct node* sum = add(a, b);
    printf("Sum:\n");
    display(sum);
    return 0;
}
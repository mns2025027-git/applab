// 2. Suppose the user wants to change a zero to a non-zero element or vice-versa. Create the
// function(s) to update the sparse matrix that is already created and stored in a linked list.
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
void update(struct node** h, int r, int c, int v)
{
    struct node *p = *h, *prev = NULL;
    while (p)
    {
        if (p->r == r && p->c == c)
        {
            if (v == 0)
            {
                if (prev)
                    prev->next = p->next;
                else
                    *h = p->next;
                free(p);
            }
            else
                p->v = v;
            return;
        }
        prev = p;
        p = p->next;
    }
    if (v != 0)
    {
        struct node* t = create(r, c, v);
        t->next = *h;
        *h = t;
    }
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
    struct node* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &r, &c, &v);
        struct node* t = create(r, c, v);
        t->next = head;
        head = t;
    }
    printf("Enter position and value to update: ");
    scanf("%d%d%d", &r, &c, &v);
    update(&head, r, c, v);
    display(head);
    return 0;
}
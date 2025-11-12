#include <stdio.h>

#define max 100

int stack[max];
int top = -1;

void push()
{
    int val;
    if (top >= max - 1)
    {
        printf("Overflow!\n");
        return;
    }
    printf("Value? ");
    scanf("%d", &val);
    stack[++top] = val;
}

void pop()
{
    if (top < 0)
    {
        printf("Underflow!");
        return;
    }
    printf("Popped %d", stack[top--]);
}
void seek()
{
    if (top < 0)
    {
        printf("-1");
        return;
    }
    printf("Top value is %d", stack[top]);
    return;
}

int main()
{
    int n;
    do
    {
        printf("\n---------------");
        printf("\n1.Push ?");
        printf("\n2.Pop ?");
        printf("\n3.Seek ?");
        printf("\n4.Exit\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            seek();
            break;
        }
    } while (n != 4);

    return 0;
}
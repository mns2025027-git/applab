#include <stdio.h>

#define max 100

int queue[max];
int front = -1, rear = -1;

void enq()
{
    if (rear >= max - 1)
    {
        printf("Overflow!");
        return;
    }

    int val;
    printf("Value?");
    scanf("%d", &val);
    if (front == -1)
        front = 0;
    queue[++rear] = val;
}

void deq()
{
    if (front == -1)
    {
        printf("Empty!");
        return;
    }
    printf("Value at the front is %d", queue[front++]);

    if (front > rear)
    {
        front = -1, rear = -1;
        return;
    }
}

void isempty()
{
    if (front == -1)
    {
        printf("Yup!");
        return;
    }
    printf("NOPE!");
}
void isfull()
{
    if (rear == max - 1)
    {
        printf("Yup!");
        return;
    }
    printf("NOPE!");
}

void traverse()
{
    if (front == -1)
    {
        printf("Empty!");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("[%d] ", queue[i]);
    }
}

int main()
{
    int n;
    do
    {
        printf("\n---------------");
        printf("\n1.Enqueue?");
        printf("\n2.Dequeue?");
        printf("\n3.Full?");
        printf("\n4.Empty?");
        printf("\n5.Traverse?");
        printf("\n6.Exit?\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        case 3:
            isfull();
            break;
        case 4:
            isempty();
            break;
        case 5:
            traverse();
            break;
        }
    } while (n != 6);

    return 0;
}
#include <stdio.h>

#define max 4

int queue[max];
int front = -1, rear = -1;

void enq()
{

    if ((rear + 1) % max == front)
    {
        printf("Full!");
        return;
    }
    int val;

    printf("Value? ");
    scanf("%d", &val);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % max;
    queue[rear] = val;
}

void deq()
{
    if (front == -1)
    {
        printf("Empty!");
        return;
    }
    printf("Value at front is %d ", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % max;
}

void traverse()
{
    if (front == -1)
    {
        printf("Empty!");
        return;
    }
    int i = front;
    while (1)
    {
        printf("[%d] ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % max;
    }
}

void isfull()
{
    if ((rear + 1) % max == front)
    {
        printf("YUP!!");
        return;
    }
    printf("NOPE!");
}

void isempty()
{
    if (front == -1)
    {
        printf("YUP!");
        return;
    }
    printf("NOPE!");
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
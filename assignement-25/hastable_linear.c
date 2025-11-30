#include <stdio.h>

#define size 10

int table[size];

void init()
{
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }
}

void insert(int data)
{
    int startindex = data % size;

    for (int i = 0; i < size; i++)
    {
        int currentIndex = (startindex + i) % size;

        if (table[currentIndex] == -1)
        {
            table[currentIndex] = data;
            return;
        }
    }
    printf("Table full!!!\n");
}

void deleteKey(int data)
{
    int startIndex = data % size;

    for (int i = 0; i < size; i++)
    {
        int currentIndex = (startIndex + i) % size;

        if (table[currentIndex] == data)
        {
            table[currentIndex] = -1;
            printf("%d deleted at pos %d \n", data, currentIndex);
            return;
        }
    }
    printf("Element %d not found!!\n", data);
}

void search(int data)
{
    int startIndex = data % size;

    for (int i = 0; i < size; i++)
    {
        int currentIndex = (startIndex + i) % size;

        if (table[currentIndex] == data)
        {
            printf("Element %d found at pos %d !\n", data, currentIndex);
            return;
        }
    }
    printf("Element %d not found!!!\n", data);
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        if (table[i] == -1)
            printf("%d : --- \n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main()
{
    init(); // clear table

    // --- Exact Sequence from Assignment ---

    insert(25); // Goes to 5
    display();

    insert(35); // Wants 5, slides to 6
    display();

    insert(15); // Wants 5, slides to 7
    display();

    insert(95); // Wants 5, slides to 8
    display();

    insert(5); // Wants 5, slides to 9
    display();

    search(35);
    search(100);
    printf("\n");

    deleteKey(15);
    display();

    deleteKey(200);
    display();

    return 0;
}
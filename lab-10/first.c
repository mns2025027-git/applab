// 1. Write a C program to sort the array of integers using Insertion
// or selection sort algorithm.
#include <stdio.h>

int minimum(int a, int b)
{
    return (a > b) ? b : a;
}

int main()
{
    int n, choice;

    printf("\n--------------------");
    printf("\n1.Insertion Sort?");
    printf("\n2.Seleciton Sort?");
    scanf("%d", &choice);

    printf("\nNumber of elements?");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the elements for the array:");

    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        arr[i] = k;
    }

    switch (choice)
    {
        case 1:
            for (int i = 0; i < n; i++)
            {
                int k = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > k)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = k;
            }
            break;
        case 2:
            for (int i = 0; i < n - 1; i++)
            {
                int min = arr[i], index = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < min)
                    {
                        min = arr[j];
                        index = j;
                    }
                }
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }

            break;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
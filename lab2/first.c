#include <stdio.h>

void reverse_array(int a[], int n)
{
    int first = 0, last = n - 1;
    while (first < last)
    {
        int temp = a[first];
        a[first] = a[last];
        a[last] = temp;
        first++, last--;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    reverse_array(a, n);

    printf("\nReversed Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
#include <stdio.h>

int midpoint(int a[], int n)
{
    int total = 0, left_sum = 0;

    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int right_sum = total - left_sum - a[i];
        if (right_sum == left_sum)
        {
            return i;
        }
        left_sum += a[i];
    }
    return -1;
}

int main()
{
    int a[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(a) / sizeof(a[0]);

    int index = midpoint(a, n);

    if (index != -1)
        printf("%d", index);
    else
        printf("Sorry! no index found...");

    return 0;
}
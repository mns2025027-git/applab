#include <stdio.h>
int main()
{
    int a = 10;
    int* j;
    void* k;
    j = k = &a;
    j++, k++;
    printf("%d,%d", j, k);
}
#include <stdio.h>

int count()
{
    char c = getchar();
    if (c == '\n') return 0;
    if (c == ' ') return count();
    return 1 + count();
}
int main()
{
    int n;
    printf("Enter the string: ");
    n = count();
    printf("\n%d total letters!", n);
    return 0;
}
#include <stdio.h>

void reverse()
{
    char c = getchar();
    if (c == '\n') return;
    reverse();
    putchar(c);
}
int main()
{
    printf("Enter a string: ");
    reverse();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void generateMagicSquare(int n)
{
    if (n % 2 == 0)
    {
        printf("Magic square is only exist for odd inteager n.\n");
        return;
    }

    int magic[n][n];

    // Initialize all cells to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) magic[i][j] = 0;

    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n)
    {
        magic[i][j] = num;

        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;

        if (magic[next_i][next_j] != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = next_i;
            j = next_j;
        }

        num++;
    }

    // Print the magic square
    printf("\nMagic Square of size %d:\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("%4d ", magic[i][j]);
        printf("\n");
    }

    // Optional: Print the magic constant
    int magicConstant = n * (n * n + 1) / 2;
    printf("\nMagic Constant Number = %d\n", magicConstant);
}

int main()
{
    int n;
    printf("Enter an odd number for magic square matrix size: ");
    scanf("%d", &n);

    generateMagicSquare(n);
    return 0;
}
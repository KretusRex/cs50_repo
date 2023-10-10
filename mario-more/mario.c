#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get pyramid height, positive integer

    int n;
    do
    {
        n = get_int("size: ");
    }
    while (n < 1 || n > 15);
    // this loop renders rows (shift to next line)
    for (int i = n; i > 0; i--)
    {
        // this loop draws columns
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        for (int j = n; j >= i; j--)
        {
            printf("#");
        }

        printf("  ");

        for (int j = n; j >= i; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}

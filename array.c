#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("length: \n");
    }
    while (length < 1);

    int twice[length];

    for (int i = 0; i < length; i++)
    {
        twice[i] = 2 * twice[i - 1];
        printf("%i\n", twice[i] );
    }
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
string message;
void print_bulb(int bit);

int main(void)
{
    // TODO
    message = get_string("Enter message to be encrypted: \n");

    for (int i = 0; i < strlen(message); i++) // loop that runs throught the input array
    {
        int c = message[i]; // converting letters to ASCII
                            // convert to bits
        int bit[BITS_IN_BYTE];
        int j = 0;

        while (j < BITS_IN_BYTE)
        {
            bit[j++] = c % 2;
            c /= 2;
            // printf("J: %i", j);
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(bit[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

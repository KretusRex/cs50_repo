#include <cs50.h>
#include <stdio.h>

int sum_doubles(int other);
long int card;
int sum_even = 0;
int sum_other = 0;
int other;
int card_length = 0;

int main(void)

{

    card = get_long("Enter credit card number: \n");

    long int l = card;

    // checking card length
    do
    {
        l = l / 10;
        card_length++;
    }
    while (l > 0);
    // printf("card is %i digits long\n", card_length);

    // check if length is OK - 13 15 or 16 digits

    if (card_length != 13 && card_length != 15 &&
        card_length != 16) // checking if length of the card matches desired length of card numbers
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {

    long int cardchk = card; // cardchk - storing card number

    int y = 0;

    do
    {

        int even = cardchk % 10; // gets the last digit
        cardchk = cardchk / 10;
        //  printf("even %i\n", even);
        sum_even += even;

        other = cardchk % 10;
        cardchk = cardchk / 10;
        y = sum_doubles(other);
        sum_other = sum_other + y;
        //  printf("other %i\n", other);

        // shortens the string by 1 last other
    }
    while (cardchk > 0);

    //  printf("checked.\n");
    // printf("sum of others: %i\n", sum_other);
    // printf("sum of evens: %i\n", sum_even);

    int sum_all = sum_other + sum_even;
    // printf("CHECKSUM: %i\n", sum_all);
    sum_all = sum_all % 10;

    // else
    // {
    // printf("checksum valid\n");
    // }

    // check if amex
    if (card_length == 15 && sum_all == 0)
    {
        long int amexchk = card;
        while (amexchk > 38)
        {
            amexchk = amexchk / 10;
        }
        if (amexchk == 34 || amexchk == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // end check if amex
    // check if visa

    else if (card_length == 13 && sum_all == 0)
    {
        long int visachk = card;
        while (visachk > 9)
        {
            visachk = visachk / 10;
        }
        if (visachk == 4)
        {
            printf("VISA\n");
        }
    }
    else if (card_length == 13 && sum_all == 0) // visa check
    {
        long int visachk = card;
        while (visachk > 9)
        {
            visachk = visachk / 10;
        }
        if (visachk == 4)
        {
            printf("VISA\n");
        }
    } // visa check ends

    else if (card_length == 16 && sum_all == 0) // MC check
    {
        long int mcchk = card;
        while (mcchk > 99)
        {
            mcchk = mcchk / 10;
        }
        if (mcchk > 50 && mcchk < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (mcchk < 50 && mcchk > 39)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
}
int sum_doubles(int digit)
{
    digit = digit * 2;
    if (digit >= 10)
    {
        digit = 1 + digit % 10;
        return digit;
    }
    return digit;
}

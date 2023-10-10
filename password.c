// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);
int arr_length;

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // transform string to integers

    int uppercase = 0;
    int lowercase = 0;
    int special = 0;
    int number = 0;

    for (int i = 0; i < strlen(password); i++)
    {
        char c = password[i];
        int check = c;

        if (check > 64 && check < 91)
        {
            uppercase++; // count uppercase, summrazie and pass if the number of them is > 0
        }
        else if (check > 96 && check < 123)
        {
            lowercase++; // count lowercase, summarize and pass if the number of them is > 0
        }
        else if (check > 32 && check < 48)
        {
            special++; // count symbols, summarize and pass if the number of them is > 0
        }
        else if (check > 57 && check < 65)
        {
            special++; // count symbols, summarize and pass if the number of them is > 0
        }
        else if (check > 90 && check < 97)
        {
            special++; // count symbols, summarize and pass if the number of them is > 0
        }
        else if (check > 122 && check < 127)
        {
            special++; // count symbols, summarize and pass if the number of them is > 0
        }
        else if (check > 47 && check < 58)
        {
            number++; // count numbers, summarize and pass if the number of them is > 0
        }

        if (number * special * uppercase * lowercase != 0)
        {
            return true;
        }
    }
    return false;
}
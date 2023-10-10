// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string argument);

int main(int argc, string argv[])
{
    // checking if proper number of command line arguments
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    } // end of command-line check

    string voweled = argv[1]; // defining the original string to be modified

    string devoweled = replace(voweled);

    printf("%s\n", devoweled);


    return 0;
}

string replace(string argument)
{
    string output = argument;

    for (int i = 0; i < strlen(argument); i++ )
        {
            char c = tolower(argument[i]);

            switch (c)
            {
                case 'a':
                    output[i] = '6';
                    break;

                case 'e':
                    output[i] = '3';
                    break;

                case 'i':
                    output[i] = '1';
                    break;

                case 'o':
                    output[i] = '0';
                    break;
                default:
                    output[i] = c;
            }

        }

        return output;
}
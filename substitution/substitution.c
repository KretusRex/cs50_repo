#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{


    // Points assigned to each letter of the alphabet
    int cipher[26];
    char plain;
    int compute_score(string word);
    int n;

    int main(int argc, string argv[])
    {
        // get length of array
        n = 0;

        while (cipher[n] != '') // Count number of characters up until '\0' (aka NUL)
        {
            n++;
        }
        // Get input words from both players
        string word1 = get_string("Player 1: ");


        // Score both words
        int score1 = compute_score(word1);
        int score2 = compute_score(word2);

        if (score1 == score2)
        {
            printf("Tie!\n");
        }
        else if (score1 > score2)
        {
            printf("Player 1 wins!\n");
        }
        else if (score1 < score2)
        {
            printf("Player 2 wins!\n");
        }
        // TODO: Print the winner
    }

    int compute_score(string word)
    {
        int sum = 0;
        int i = 0;
        int f = 0;

        for (i = 0; i < strlen(word); i++) // first repeat the next steps for each letter in word
        {
            char c = tolower(word[i]);

            for (f = 0; f < n; f++)
            {
                if (c == letter[f])
                    sum += POINTS[f];
            }
        }
        return sum;
        // TODO: Compute and return score for string
    }
}
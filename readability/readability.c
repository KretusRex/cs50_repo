#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string text;
float L;
float S;
int lowercase = 0;
int uppercase = 0;
int space = 1;
float sentence;
int letters;
int words = 0;
int sen_end = 0;
int count_letters(string text);

int main(void)
{
    text = get_string("Enter text to be evaluated: ");

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        int check = c;

        if (check > 64 && check < 91)
        {
            uppercase++; // count uppercase, summrazie and pass if the number of them is > 0
        }
        else if (check > 96 && check < 123)
        {
            lowercase++; // count lowercase, summarize and pass if the number of them is > 0
        }
        else if (check == 32)
        {
            space++; // count symbols, summarize and pass if the number of them is > 0
        }
        else if (check == 46 || check == 33 || check == 63)
        {
            sen_end++; // count symbols, summarize and pass if the number of them is > 0
        }
    }
    // printf("sum of letters: %i\n", uppercase + lowercase);
    // printf("sum of spaces: %i\n", space);
    // printf("sum of end of sentence: %i\n", sen_end);

    // time to do the math
    letters = uppercase + lowercase;
    words += space;
    // printf("sum of words %i\n", words);
    L = letters / (double) words * 100;
    // if (sen_end == 0)
    // {
    //    sentence = 1;
    // }
    // else
    sentence = sen_end;
    // printf("number of sentences %i\n", sentence);
    S = sentence / (double) words * 100;
    // printf("S: %f\n, L: %f\n", S, L);
    float index;
    float index2;
    float index3;
    int grade;

    index = 0.0588 * L;
    index2 = 0.296 * S;
    index3 = index - index2 - 15.8;
    grade = round(index3);
    // printf("index: %f\n index2: %f\n", index, index2);
    if (index3 < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index3 > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    // 0,0588 * 464,29 - 0,296 * 28,57 - 15,8

} // return false;
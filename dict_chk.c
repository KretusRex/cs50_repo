#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int main(int argc, char *argv[])
{
    int max_len = 0;
    int min_sum = 99999999;
    int max_sum = 0;
    int chk = 0;
    int word_count = 0;
    char buffer[45];
    int sum;
    int total = 0;
    if (argc != 2)
    {
        printf("Usage: ./dict_chk [path/filename]\n");
        return 1;
    }
    FILE *dict = fopen(argv[1], "r");
    if (dict == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), dict) != NULL)
    {
        chk = strlen(buffer) - 1;
        sum = 0;
        for (int i = 0; i < chk; i++)
        {
            char c = buffer[i];
            int a = c;
            if (isalpha(c) != 0)
            {
                sum +=tolower(a);
            }
        }
        total +=sum;
        //buffer[chk] = '\0';
        //printf("%s | word sum: %i wordlen: %i \n", buffer, sum, chk);
        word_count++;
        if (chk > max_len)
        {
            max_len = chk;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        if (sum < min_sum)
        {
            min_sum = sum;
        }
    }
    int wordlen[max_len];

    printf("max length of word is: %i \n", max_len);
    printf("word count: %i \n", word_count);
    printf("max sum: %i\n", max_sum);
    printf("min sum: %i\n", min_sum);
    printf("total: %i\n", total);
    printf("avh: %i\n", total/word_count);
    fclose(dict);
}
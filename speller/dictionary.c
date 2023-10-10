// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
int dict_word_count = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashed = hash(word);
    node *cursor = table[hashed];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int hash_value = 0;
    for (int i = 0; i < 15 && word[i] != '\0'; i++)
    {
        hash_value += (tolower(word[i]) - 'a') * (tolower(word[i]) - 'a');
    }
    end of good code */

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    { // TODO

        char word[LENGTH + 1];
        FILE *loaded_dict = fopen(dictionary, "r");
        if (!loaded_dict)
        {
            printf("Error opening file!\n");
            return 1;
        }
        while (fscanf(loaded_dict, "%s", word) != EOF)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }
            dict_word_count++;
            strcpy(n->word, word);
            n->next = NULL;
            int index = hash(n->word);
            if (table[index] == NULL)
            {
                table[index] = n;
                n->next = NULL;
            }
            else
            {
                n->next = table[index];
                table[index] = n;
            }
        }
        fclose(loaded_dict);
        int error = 0;
        for (int i = 0; i < N; i++)
        {
            node *cursor = table[i];
            if (cursor == NULL)
            {
                error++;
            }
            while (cursor != NULL)
            {
                cursor = cursor->next;
            }
        }
        printf("errors: %i\n", error);
        printf("dictionary contains %i words\n", dict_word_count);
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *pointer = table[i];

        while (pointer != NULL)
        {
            node *tmp = pointer;
            pointer = pointer->next;
            free(tmp);
        }
        free(pointer);
    }

    return true;
    return false;
}

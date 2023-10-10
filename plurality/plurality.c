#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // strcomp to check the vote against the candidated list
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            // printf("Candidate exists \n");
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    candidate swap_candidate;

    int i = 0;
    int j = 0;

    while (j < candidate_count - 1)
    {
        for (i = 0; i < candidate_count - 1 - j; i++)
        {
            // sort the candidates by score

            if (candidates[i].votes < candidates[i + 1].votes)
            {
                swap_candidate = candidates[i];
                candidates[i] = candidates[i + 1];
                candidates[i + 1] = swap_candidate;
            }
        }
        j++;
    }
    int v = 0;
    // make a loop that will print names with same highest score
    printf("%s\n", candidates[v].name);

    while (v >= 0 && candidates[v].votes == candidates[v + 1].votes)
    {
        printf("%s\n", candidates[v + 1].name);
        v++;
    }
}
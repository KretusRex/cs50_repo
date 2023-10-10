#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_pop;
    int years_elapsed = 0;
    int end_pop;

    do
    {
        start_pop = get_int("population starting size: ");
    }
    while (start_pop < 9);
    // printf("desired population start size is %i\n", start_pop);

    // TODO: Prompt for end size

    do
    {
        end_pop = get_int("population ending size: ");
    }
    while (end_pop < 9 || end_pop < start_pop);
    // printf("desired population ending size is %i\n", end_pop);

    // TODO: Calculate number of years until we reach threshold

    while (start_pop < end_pop)
    {
        start_pop = start_pop + (start_pop / 3) - (start_pop / 4);
        years_elapsed++;
    }

    // TODO: Print number of years

    printf("Years: %i\n", years_elapsed);
}

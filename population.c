#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years,died,born;
    for (years = 0; start < end; years++)
    {
        died = start / 4;
        born = start / 3;
        start = start - died + born;
    }
   
    // TODO: Print number of years
    printf("Years: %i\n", years);

}

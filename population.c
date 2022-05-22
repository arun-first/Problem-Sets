#include <cs50.h>
#include <stdio.h>

int main(void) {
    // variables to hold the starting & ending year
    int strt_size = 0, end_size = 0, years = 0;

    // getting the population input
    do {
        strt_size = get_int("Start size: ");
        end_size = get_int("End size: ");
    } while (strt_size < 9 || end_size < strt_size);

    // calculating the years required
    while (end_size > strt_size) {
        int born = strt_size / 3;
        int dead = strt_size / 4;
        strt_size = strt_size + born - dead;
        years++;
    }

    // printing the years required
    printf("Years: %i\n", years);
}
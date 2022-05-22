#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // getting the change
    float dollars = 0.0;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100); // rounding off

    // calculating the coins required
    int coins = 0;
    while (cents > 0)
    {
        // decreasing the cents as well as increasing the coins
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else if (cents >= 1)
        {
            cents -= 1;
        }
        else
        {
            // TODO: nothing
        }

        coins++; // incrementing the coins
    }

    // printing the number of coins
    printf("Coins: %i\n", coins);
}
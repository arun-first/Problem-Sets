#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // necessary variables
    long debit_card = 0;
    int even_sum = 0, odd_sum = 0, net_sum = 0, counter = 1;
    int digits = 0;
    string card_type;

    // getting the input
    do
    {
        debit_card = get_long("Card: ");
    }
    while (debit_card < 1);

    long number = debit_card; // as a copy

    // implementing luhn's algorithm
    while (debit_card > 0)
    {
        int a = debit_card % 10;

        // check for position
        if (counter % 2 == 0)
        {
            a *= 2; // multiplying by 2
            while (a > 9)
            {
                even_sum += a % 10; // counting digit-wise
                a /= 10; // removing the digit
            }
            even_sum += a;
        }
        else
        {
            odd_sum += a;
        }

        debit_card /= 10; // removing a from debit_card
        counter++; // incrementing the counter
        digits++; // counting the digits
    }

    // getting the first letter
    int a = number / pow(10, digits - 1); // first digit
    int b = number / pow(10, digits - 2); // second digit

    // getting the card type
    switch (b)
    {
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            card_type = "MASTERCARD";
            break;
        case 34:
        case 37:
            card_type = "AMEX";
            break;
        default:
            card_type = "INVALID";
    }

    if (a == 4)
    {
        card_type = "VISA";
    }

    // getting the net sum
    net_sum = even_sum + odd_sum;

    // validity check
    if (net_sum % 10 == 0 && digits >= 13)
    {
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}
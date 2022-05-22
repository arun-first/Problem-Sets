#include <cs50.h>
#include <stdio.h>
#include <string.h>

// integer arithmetic functions
bool is_num(char a); // checks for character to be alpha-numeric
int convert_c_to_i(string s); // converts alpha-numeric integer to integer
int power(int n, int m); // to count a number to a certain power
int convert_charac_to_i(char a); // converts character to an int

// string arithmetic functions
char cipher(char a, int key); // to encrypt a particular character
int index_overflow(int index, bool cas_e); // checks for index to go out of bounds
void scramble(string txt, int key); // scrambles a whole sentence as per the key

int main(int argc, string argv[])
{
    // getting the key
    int key = 0;
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!is_num(argv[1][i]) || argv[1][0] == '-') // check for character as well as negative
            {
                printf("usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    key = convert_c_to_i(argv[1]);

    // getting the plain text
    string plain_txt = get_string("plain text: ");
    scramble(plain_txt, key);
}

// function to scramble the text
void scramble(string txt, int key)
{
    printf("cipher text: ");
    // iterating over the string
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        char a = txt[i]; // individual character
        if ((a <= 91 && a >= 65) || (a <= 122 && a >= 97)) // check for letters
        {
            printf("%c", cipher(a, key));
        }
        else
        {
            printf("%c", a);
        }
    }
    printf("\n");
}

// function to check alpha-numeric
bool is_num(char a)
{
    switch (a)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
            break;
        default:
            return false;
    }
}

// converts string to int
int convert_c_to_i(string s)
{
    int num = 0; // to store the number

    // iterating through the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char a = s[i]; // individual character
        if (is_num(a))
        {
            num += power(10, n - (i + 1)) * convert_charac_to_i(a); // building up the number
        }
    }
    return num;
}

// power calculator
int power(int n, int m)
{
    int num = 1;
    if (m == 1) // cross check
    {
        return n;
    }
    for (int i = 0; i < m; i++) // counts the number up to a certain power (m)
    {
        num = n * n;
    }
    return num;
}

// converts characters to ints
int convert_charac_to_i(char a)
{
    switch (a)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
    return 1; // by-default return type
}

// encrypts a character according to a particular key
char cipher(char a, int key)
{
    int index = 0; // to hold the index of encrypted character

    // checking the case
    if (a <= 122 && a >= 97)
    {
        index = ((a - 97) + key) % 26;
        index = index_overflow(index + 97, false);
    }
    else
    {
        index = ((a - 65) + key) % 26;
        index = index_overflow(index + 65, true);
    }
    return (char)(index);
}

// checks the index to overflow (go out of bounds)
int index_overflow(int index, bool cas_e)
{
    if (cas_e)
    {
        return (index > 97) ? (index - 97) + 65 : index;
    }
    else
    {
        return (index > 122) ? (index - 122) + 97 : index;
    }
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char to_lower(char a); // to convert letter to lowecase

int main(int argc, string argv[])
{
    // getting the key string
    string key = "";
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            key = argv[1];
        }
        else
        {
            printf("usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("usage: ./caesar key\n");
        return 1;
    }

    // getting the plain text
    string plain_txt = get_string("plain text: ");
    printf("cipher text: ");

    // encrypting
    for (int i = 0, n = strlen(plain_txt); i < n; i++)
    {
        char a = plain_txt[i]; // individual character

        // check for letters
        if ((a <= 122 && a >= 97) || (a <= 91 && a >= 65))
        {
            if (a <= 122 && a >= 97) // lowercase
            {
                printf("%c", to_lower(key[a - 97]));
            }
            else // uppercase
            {
                printf("%c", key[a - 65]);
            }
        }
        else
        {
            printf("%c", a);
        }
    }
    printf("\n");
}

// converting to lowecase
char to_lower(char a)
{
    if (a <= 122 && a >= 97)
    {
        return a;
    }
    else
    {
        return a + 32;
    }
}
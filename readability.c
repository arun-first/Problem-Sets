#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_index(string text); // count the letters

int main(void)
{
    // getting the text
    string text = get_string("Text: ");
    int index = count_index(text); // getting the index

    // printing the index
    if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_index(string text)
{
    // necessary variables
    int letters = 0, words = 0, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char a = text[i];
        if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) // check for letters
        {
            letters++;
        }

        // check for words
        if ((a == ',' || a == ' ' || a == '.' || a == '!') && !(text[i - 1] == ',' || text[i - 1] == '.' || text[i - 1] == '!'))
        {
            words++;
        }

        // check for sentences
        if (a == '.' || a == '?' || a == '!')
        {
            sentences++;
        }
    }

    // calculating the average
    float l_avg = (float) letters / words * 100;
    float s_avg = (float) sentences / words * 100;

    int index = round((0.0588 * l_avg - 0.296 * s_avg - 15.8)); // calculating the index

    return index;
}
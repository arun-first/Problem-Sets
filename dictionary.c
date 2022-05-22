// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];
int num_words_loaded = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int n = strlen(word);
    char t[LENGTH + 1];
    for(int i = 0; i < n; i++)
    {
        t[i] = tolower(word[i]);
    }
    t[n] = '\0';
    int hc = hash(t);

    // iterating through the linked list
    for (node *tmp = table[hc]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_code = 0;

    // generating the hash code
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        hash_code += word[i];
    }
    hash_code %= N;
    return hash_code;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // opening the file
    FILE *ptr = fopen(dictionary, "r");
    if (ptr == NULL)
    {
        return false;
    }

    // reading the characters
    char wds[LENGTH + 1];
    while ((fscanf(ptr, "%s", wds)) != EOF)
    {
        int hc = hash(wds);
        node *n = malloc(sizeof(node));
        strcpy(n->word, wds);
        n->next = table[hc];
        table[hc] = n;
        num_words_loaded++;
    }
    fclose(ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return num_words_loaded;
}

// freeing a linked list
void free_ll(node *head)
{
    while(head != NULL)
    {
        node *tmp = head->next;
        free(head);
        head = tmp;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        free_ll(table[i]);
    }
    return true;
}
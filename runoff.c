#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // iterating over the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check for name match
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; // updating the number of votes PREFERENCES[VOTER][PREFERENCE] = CANDIDATE
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    /**
     * [1] ITERATE THROUHGH THE VOTER'S BALLOT
     * [2] CHECK FOR CANDIDATE TO BE NOT ELIMINATED
     * [3] IF NOT ELIMINATED, UPDATE THE VOTES [FIRST PREFERENCE]
     * [4] IF ELIMINATED, GO FOR THE SECOND ONE
     */
    // iterating through the voter's ballot
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++) // iterating through the candidate's in the ballot
        {
            // check for candidate's elimination
            if (!candidates[preferences[i][j]].eliminated) // PREFERENCES[VOTER][PREFERENCE] = CANDIDATE
            {
                candidates[preferences[i][j]].votes++; // updating the votes
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes > voter_count / 2)
            {
                printf("%s\n", candidates[i].name);
                return true;
            }
        }
    }
    return false;
}

// Return the minimum number of votes any remainitial check
int find_min()
{
    int min_vote = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (min_vote < candidates[i].votes && candidates[i].eliminated == false)
        {
            min_vote = candidates[i].votes;
        }
    }

    return min_vote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int tie_num = 0; // as a counter
    int remaining_candidate = candidate_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false) // check for elimination
        {
            if (min == candidates[i].votes)
            {
                tie_num++;
            }
        }
        else
        {
            remaining_candidate--;
        }
    }

    if (tie_num == remaining_candidate)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}

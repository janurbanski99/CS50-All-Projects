#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];        //[voter][voter's preference], np. [0][0] = 2 -> 1 głosujący, 1 miejsce = 3 kandydat

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
        printf("Usage: ./runoff [candidate ...]\n");
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
            if (!vote(i, j, name))  //i = voter, j = rank
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
//        for (int i = 0; i < candidate_count; i++)
//        {
//            printf("%i  ",candidates[i].votes);
//        }
//        printf("\n");


        // Calculate votes given remaining candidates
        tabulate();

//        for (int i = 0; i < candidate_count; i++)
//        {
//            printf("%i  ",candidates[i].votes);
//        }
//        printf("\n");

//        break;

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        //printf("%i", min);
        //break;
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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp (candidates[i].name, name) == 0)           //można też później ew. zupgradować żeby równo traktowało wielkie i małe litery
        {
            preferences[voter][rank] = i;       //zapisuje indeks danej preferencji
            //printf("%i %i %i \n", voter, rank, i);
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)   //dla każdego elementu tej 2d tablicy //mam wziąć pierwszego i sprawdzić czy nie jest wyeliminowany i dodać, na reszcie się ne skupiać ju
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)      //preferences[i][j] wskazuje na indeks kandydata wybranego jako 1 wybór
            {
                candidates[preferences[i][j]].votes += 1;
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
        if (candidates[i].votes > voter_count / 2)
        {
            printf("Winner: %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min;
    for (int i = 0; i < candidate_count - 1; i++)                     //tylko dla kandydatów co nadal są w grze conie (.eliminated == false)
    {
        if (candidates[i].eliminated == false && candidates[i].votes <= candidates[i+1].votes)
        {
            min = candidates[i].votes;  //chyba trzeba popatrzeć na czy głosy kandydata i+1 są większe od i i wtedy coś
        }
        else if (candidates[i].eliminated == false && candidates[i].votes >= candidates[i+1].votes)  //może nie być [i+1]
        {
            min = candidates[i+1].votes;
            if (candidates[i+1].votes == 0)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min)   //tu zmieniłem z ==
        {
            return false;
        }
    }
    printf("Tie between:\n");
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)         //jeszcze sprawdzić czy dobrze bd z 4 kandydatem (w sensie czy usunie 2 jak bd 3 na a 3 na B 2 na C 2 na D)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            printf("Eliminating candidate %s\n", candidates[i].name);
        }
    }
    return;
}
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; //0 - 25

int compute_score(string word);

int main(void)
{
    // Get input words from both players

    string word1 = get_string("Player 1: ");       //wypisać też liczbę pkt żeby zobaczyć czy się zgadza
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //printf("Score 1: %i\n", score1);
    //printf("Score 2: %i\n", score2);
    // TODO: Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)      //A = 65  Z = 90
{
    //przerobić na tylko wielkie litery
    int score = 0;
    int rotation = 65;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = toupper(word[i]);
        if ((int) word[i] >= 65 && (int) word[i] <= 90)
        {
            //word[i] = (int) word[i] - 65;
            word[i] = POINTS[(int) word[i] - rotation];   //tu z tą 65 pewnie coś trzeba bd zrobić, można by też napisać - 'A' po prostu
            //printf("%i\n", score);  //to mi daje pozycję w tabeli
        }
        else
        {
            word[i] = 0;
        }
        score = score + word[i];
    }
    return score;
    // TODO: Compute and return score for string
}
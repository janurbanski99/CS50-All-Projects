#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = get_int("How many scores?: ");

    int scores[n];

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);   //dajemy 3.0 zamiast 3 żeby nam się zamieniło na float (wystarczy tylko 1 liczba w działaniu)

}
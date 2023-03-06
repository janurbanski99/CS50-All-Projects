#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Gib text: ");

    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sent = count_sentences(text);

    //printf("%i letters\n", num_letters);
    //printf("%i words\n", num_words);
    //printf("%i sentences\n", num_sent);

    int index = round(0.0588 * ((float)num_letters / (float)num_words * 100) - 0.296 * ((float)num_sent /
                      (float)num_words * 100) - 15.8);
    //pamiętać że przy dzieleniu intów też dostajemy inta więc może być źle zaokrąglone aaa

    //printf("%i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    //pewnie trzeba bd użyć funkcji round
    //pamiętać o rozdzieleniu zdań nie tylko kropką ale też ! ?
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]))
        {
            count += 1;
        }
        else if (isupper(text[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count += 1;
        }
    }
    return count + 1; // +1 dlatego że ostatnie zdanie zwykle nie kończy się spacją conie
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count += 1;
        }
    }
    return count;
}
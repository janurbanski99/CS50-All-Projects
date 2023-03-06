#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//#include <stdbool.h>

bool only_digits(string key);
char rotate(char c, int user_key);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int user_key = atoi(argv[1]);
    string plaintext = get_string("Gib plaintext: ");
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], user_key));
    }
    printf("\n");
    //string ciphertext = rotate(plaintext, user_key);
}

bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i]) == false)
        {
            return false;
        }
    }
    return true;
    //return 0;
}

char rotate(char c, int user_key)
{
    if isalpha(c)
    {
        if isupper(c)
        {
            return (char)(c - 'A' + user_key) % 26 +
                   'A';   //26 bo alfabet ma 26 cyfr i żeby jak ktoś da np kod 100 to zamiast a robiła się inna litera nadal a nie jakiś znak z dupy zgodnie z ASCII
        }
        if islower(c)
        {
            return (char)(c - 'a' + user_key) % 26 + 'a';
        }
    }

    return c;
}
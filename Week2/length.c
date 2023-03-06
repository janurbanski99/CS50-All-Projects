#include <stdio.h>
#include <cs50.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0') // \0 to znak dodawany zawsze na końcu każdego str (i tylko str bo tylko to ciężko było zdefiniować ile bajtów powinien zajmować)
    {
        i++;
    }
    return i;
}

//a wsm to można by się tego wszystkiego pozbyć i dodać tylko bibliotekę <string.h>  i kodzik
//string name = get_string("Name: ");
//int length = strlen(name);
//printf("%i\n", length);
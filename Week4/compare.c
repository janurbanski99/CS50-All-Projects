#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Gib s: ");
    string t = get_string("Gib t: ");

    if (strcmp(s,t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
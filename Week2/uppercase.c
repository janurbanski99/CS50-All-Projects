#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);   //dajemy -32 bo w ASCII taka jest różnica pomiędzy małymi a wielkimi literami (nie działa z pl literami uh)
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
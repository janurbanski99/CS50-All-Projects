#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)  //małe ulepszenie żeby było trochę bardziej wydajne - długość s wystarczy tylko raz zapamiętać, a for loop pozwala tak to dopisać sb
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
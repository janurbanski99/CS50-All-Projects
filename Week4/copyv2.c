#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    string s = get_string("Gib s: ");

    string t = s; //tutaj s i t wskazują na to samo hi! w pamiięci więc później dla obydwu jest zrobione Hi! (z dużej)

    printf("%p\n", s);
    printf("%p\n", t);

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
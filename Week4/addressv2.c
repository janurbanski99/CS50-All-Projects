#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = "HI!";    //to samo co string s
    char c = s[0];
    char *p = &s[0];    //jakby tu było &c to wtedy inne adresy, bo c jest kopią s[0], ale to nie jest to samo co s[0] conie

    printf("%p\n", p);
    printf("%p\n", s);  //to jest po prostu adres "H" w pamięci RAM
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);  //kolejne znaki w ciągu są tuż obok siebie, różnica 1 bita w pamięci
}
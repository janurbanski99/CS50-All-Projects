#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    printf("%i %i %i\n", s[0], s[1], s[2]);  //można se tak zamieniać na liczby - korzysta wtedy z ASII conie
    int i = 72;
    printf("%i\n", i);    //czy da się żeby z tego 72 sie zrobiła literka?  w sensie tak jak wyżej tylko na odwrót
}
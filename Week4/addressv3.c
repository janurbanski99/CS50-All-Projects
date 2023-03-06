#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);     // s adres pierwszego znaku w stringu, więc jeśli chcę go wyprintować (ten znak) to można użyć *s conie
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2)); //to działa bo wiemy że kolejne znaki w stringu są od siebie oddalone w pamięci o 1,  ale działa też np na intach,
                            //które zajmują więcej (4 bajty) bo kompilator traktuje to jako ,,przesuń się o 1 piece of data", jest no
                            //sprytny jakby xd
    //można też robić pointers arythemtics:
    printf("%s\n", s);
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);

    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

}

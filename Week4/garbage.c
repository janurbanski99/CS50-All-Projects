#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);      //nie przypisujemy do tabeli żadnych wartości i potem chcemy je wyprintować to komputer używa jakichś
                                        //"garbage" values z pamięci komputera - generalnie nie robić tego xd i przypisywać wartości
    }
}
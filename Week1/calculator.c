#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");    //gdy dzielimy int przez int to odpowiedzią zawsze bd int, nawet jeśli nowa zmianna ma inny typ danych
    float z = (float) x / y;           //można zmienić dzięki np. (float) x
    printf("%f\n", z);
}
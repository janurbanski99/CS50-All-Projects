#include <stdio.h>
#include <cs50.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;
                            // pierwsza fukcja z tmp (bez *) nie działała bo jak się wywołuje funkcje z jakichś wartości to ona działa na kopiach
                            //tych wartości (kopia x a nie x sam w sobie)
    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);   //musi być & bo to co przekazujemy funkcji musi być adresem x i y (żeby móc je modyfikować tak ładnie jak w fukcji)
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)     //x i y są pod jakimiś adresami, niech bd 0x123 i 0x456; więc a = 0x123;  b = 0x456
{
    int tmp = *a;   //tmp = to co jest pod adresem a (czyli 1 w tym przypadku) -> tmp = 1
    *a = *b;        //przypisz temu co jest pod adresem a (czyli pod 0x123) to co jest pod adresem b (czyli pod 0x456) -> x = 2
    *b = tmp;       //przypisz temu co jest pod adresem b (czyli pod 0x456) 1 -> y = 1
}
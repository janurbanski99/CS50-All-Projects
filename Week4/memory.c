#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (void)
{
    int *x = malloc(3 * sizeof(int));    //bo chcemy 3 int a jeden int waży sizeof(int) (zwykle 4)  //malloc zwraca adres ,,of the first
                                                                                                    //byte of that chunk" (jako tablicę)
    //tu użycie konsolowej fukcji valgrind
}
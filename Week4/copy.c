#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    string s = get_string("Gib s: ");

    string t = s; //tutaj s i t wskazują na to samo hi! w pamiięci więc później dla obydwu jest zrobione Hi! (z dużej)

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);



    char *a = get_string("Gib a: ");

    if (a == NULL)
    {
        return 1;
    }

    char *b = malloc(strlen(a) + 1); //potrzebujemy pamięci na strlen + 1 bo na końcu każdego stringa jest to \0 conie

    if (b == NULL)      //na wypadek jakby nie było już miejsca (np zamiast kilku znaków ktoś pierdolnie jakiś esej),   pointer zwraca taką wartość gdy ne ma miejsca właśnie
    {
        return 1;
    }

    strcpy(b, a);  //    <--- wrsja newschool,   kopiuje już razem z tym \0; (najpierw podajemy destination później source - co kopiujemy)

   //for (int i = 0, n = strlen(a) + 1; i < n; i++)
    //{
    //    b[i] = a[i];      <---- wersja oldschoolowa
    //}

    if (strlen(b) > 0)      //na wypadek jakby użytkowanik nie wpisał litery lub nic nie wpisał
    {
        b[0] = toupper(b[0]);
    }

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    free(b);        //zwalniamy tylko dla tego, dla którego wywoływaliśmy też malloc - zawsze trzeba aaaa
    return 0;
}
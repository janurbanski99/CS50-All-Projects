#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; //pointer to the next element
}
node;

int main(int argc, char *argv[])
{

    node *list = NULL; //ten ,,roboczy" pointer - jeśli jest null tzn że lista jest pusta

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);   //samo argv[i] to string a nie int więc trzeba dopasować - robi to fukcja atoi

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *ptr = list; //ptr - tymczasowa zmienna
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; //żeby ,,przemieszczać" się po strzałkach pożyczając od tego na którego wskazujemy jako pierwszego
    }

    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
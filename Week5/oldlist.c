#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = realloc(list, 4 * sizeof(int))     //1 arg - który chunk of memory chcemy rozszerzyć / zmniejszyć, 2 arg - jaki rozmiar chcemy
    if (tmp == NULL)        //musi być nowa zmienna zamiast po prostu dać list znowu na wypadek jakby się okazało że nie ma wystarczająco dużo pamięci
    {
        free(list);
        return 1;
    }
    list = tmp;  //remember that the new list points at this new chunk of memory instead

    list[3] = 4; //więc tu już można dac list zamiast temp

//tego ju nie potrzebujemy dzięki realloc

//    for (int i = 0; i < 3; i++)
//    {
//        tmp[i] = list[i];
//   }

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
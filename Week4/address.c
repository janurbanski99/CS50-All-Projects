#include <stdio.h>

int main(void)
{
    int nums[] = {1,2};
    int n = 50;
    int *p = &n;   // * musi być inaczej błąd   używm * żeby powiedzieć C że p jest pointerem (jest to adress of an integer)
    printf("%p\n", p);   //dla printowania pointerów używamy %p;     można by też napisać po prostu &n tu od razu
    printf("%i\n", *p);     //jak tu damu *p to znowu printuje się 50 - bo wtedy mamy dostęp do tego co znajduje się w tym konkretnym miejscu w pamięci (w sensie pod &n), robimy dereferance
                            //*p używa się w 2 różnych sytuacjach
    printf("%p\n", &n);
    printf("%i\n", *nums);  //działa z tablicą nie działa z intem
}



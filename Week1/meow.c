#include <stdio.h>

void meow(int n); //tutaj wkeljamy (deklarujemy) funkcję, żeby można ją było trzymać tam na dole pod int main, ; oznacza że jeszcze się tym teraz ne zajmujemy
                    //analogicznie jest z wpisywaniem bibliotek na górze - fukcje zostały wcześniej napisane i dajemy znać kompilatoriowi że będą
int main(void)
{
    meow(3);
}

void meow(int n)          //void w nawiasach oznacza że funkcja nie bierze żadnych argumentów, 1 void oznacza że funkcja niczego nie zwraca (ma jedynie visual side effects)
{                           //później zmieniamy na int n - funkcja ,,takes sth as input" (n)
    for(int i=0; n<3; i++)
    {
        printf("Meow\n");
    }
}
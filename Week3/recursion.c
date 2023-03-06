#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    int height = get_int("Gib height: ");

    draw(height);
}

void draw(int n)
{
    if (n <= 0)     //ten warunek zapewnia że ta rekurencja nie bd trwała w nieskończoność
    {
        return; //samo return bo funkcja zwraca void i tak
    }

    draw(n-1);  //n się najpierw zmniejsza (i przechodzi do pętli for) a potem zwiększa (jak już jest w pętli for)

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Gib height: ");

    draw(height);
}

void draw(int n) //void bo to funkcja nie musi nic zwracać, ma tylko ,,side effect" w postaci narysowania piramidki
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)   //i + 1 bo zawsze chcę co najmniej jedną cegiełkę wydrukować conie
        {
            printf("#");
        }
        printf("\n");
    }
}
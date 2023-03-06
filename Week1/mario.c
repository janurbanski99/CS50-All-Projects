#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);  //pętla do while jest podobna do while ale ona sprawdza warunek logiczny na końcu, podczas gdy while sprawdza go na początku
                    //dzięki temu może być zapętlona dopóki użytkownik nie poda "logicznej" wartości, gdy ją poda to pętla sb kończy
                    //można by też to zrobić z pętlą while True i z break'iem gdy warunek (np. n > 1) bd spełniony
//int m = 0;
//while (m < n)
//dla każdego rzędu
for (int m = 0; m < n; m++)
{
    // dla każdej kolumny
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    //m++;   w kom. po prostu druga opcja z użyciem while'a
}

}
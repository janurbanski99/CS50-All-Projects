#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])       //wcześniej było void co znaczyło że nie bierzemy żadnych command line arguments, a teraz mamy tak bo bierzemy
{
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}
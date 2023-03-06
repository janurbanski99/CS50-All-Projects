#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Missing command-line argument\n");
        return 1; //kiedy w programie idzie coś nie tak to powinno się zwrócić niezerową wartość z main
    }
    printf("Hello, %s\n", argv[1]);
    return 0; //jak chcemy zasygnalizować że wszystko jest ok to zwracamy 0
}
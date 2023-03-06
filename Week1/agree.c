#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? "); //tu muszą być podwójne quotes aaa - dla str podwójne (nawet jeśli jest to tylko pojedynczy znak)

    if (c == 'y' || c == 'Y') //tu muszą być pojedyncze quotes aaa - dla char pojedyncze  || to or; && to and
    {
        printf("Agreed\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not Agreed\n");
    }
}

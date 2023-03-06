#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //promt for height
    int height;
    do
    {
        height = get_int("Gib Height: ");
    }
    while (height < 1 || height > 8);

    //for(int i = 0; i < height; i++)
    int i = 0;
    while(i < height)
    {
        for (int k = i; k < height-1; k++)
        {
            printf(" ");
        }
        for(int j = -1; j < i; j++)         //bo to int j jest defionowane za każdym razem jako -1 conie, dlatego pętla daje # ## ### itd.
        {
            printf("#");
        }
    printf("\n");
    i++;
    }
}
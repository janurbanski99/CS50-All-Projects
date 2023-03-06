#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int i;
    do
    {
        i = get_int("Gib int > 0: ");
    }
    while(i <= 0);

    printf("Steps: %i\n", collatz(i));
}

int count = 0;

int collatz(int n)
{
    if (n == 1)
        return count;
    else if (n % 2 == 0)
    {
        count += 1;
        return collatz(n / 2);  // można by tez return 1 + collatz (n / 2 ) i wtedy bez countera by się obyło
    }
    else
    {
        count += 1;
        return collatz(3*n + 1);
    }
    return count;
}
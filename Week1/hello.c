#include <cs50.h>   //.h od 'header file'
#include <stdio.h>  //standard input and output

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s \n", answer); //answer wskakuje w miejsce %s po prostu, dlatego \n działa
}
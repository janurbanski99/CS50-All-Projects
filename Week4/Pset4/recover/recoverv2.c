#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    int BLOCK_SIZE = 4096;

    if (argc != 2)
    {
        printf("Usage: recover <infile>\n");
        return 1;
    }

    char *infile = argv[1];

    //open input file - memory card
    FILE *inptr = fopen(infile, "r");
    //ensure if file can be opened for reading
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    //buffer - jkbc to tu chyba może być błąd
    BYTE buffer[BLOCK_SIZE];
    int jpg_count = 0;
    char *filename = malloc(6 * sizeof(char));

    while (fread(&buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE) //może to trzeba jeszcze raz przed writem jak w volume
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //robimy new file gdzie będziemy wpisywać dane -  tu też może być błąd i może coś z tym malloc trzeba bd pokminić
            sprintf(filename, "%03i.jpg", jpg_count);
            FILE *img = fopen(filename, "w");
            fwrite(&buffer, 1, BLOCK_SIZE, img);
            jpg_count ++;
        }
    }

    free(filename);

}
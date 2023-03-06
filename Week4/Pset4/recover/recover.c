#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    //uint8_t BLOCK_SIZE = 512; //4096

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
    BYTE buffer[512];  //można by też dać z define 512 jkbc
    int jpg_c = 0;
    int jpg_f = 0;
    FILE *img = NULL;
    char *filename = malloc(8 * sizeof(char));

    while (fread(&buffer, 1, 512, inptr) == 512)
    {
        //fread(&buffer, 1, BLOCK_SIZE, inptr);
        //if start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_f == 0)
            {
                jpg_f = 1;
            }
            else
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", jpg_c);
            img = fopen(filename, "w");

            jpg_c += 1;
            //if first jpeg
                //robimy new file gdzie będziemy wpisywać dane
                //fwrite(&buffer, BLOCK_SIZE, 1, img);
             //jeśli już znalazłem jakiegoś jpga - zamknąć stary plik i otworzyć nowy
        //else - jeśli już znaleźliśmy jpga i do niego piszemy to kontynuować - write next 512 bytes (//robimy new file gdzie będziemy wpisywać dane -  tu też może być błąd i może coś z tym malloc trzeba bd pokminić)
        }
        if (jpg_f == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }

    }

    free(filename);
    fclose(inptr);
}
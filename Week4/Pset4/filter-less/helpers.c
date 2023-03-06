#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ave = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = ave;
            image[i][j].rgbtGreen = ave;
            image[i][j].rgbtBlue = ave;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int orgRed = image[i][j].rgbtRed;
            int orgGreen = image[i][j].rgbtGreen;
            int orgBlue = image[i][j].rgbtBlue;

            int newRed = round((0.393 * orgRed) + (0.769 * orgGreen) + (0.189 * orgBlue));

            if (newRed > 255.0)
            {
                image[i][j].rgbtRed = 255.0;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }

            int newGreen = round((0.349 * orgRed) + (0.686 * orgGreen) + (0.168 * orgBlue));

            if (newGreen > 255.0)
            {
                image[i][j].rgbtGreen = 255.0;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }

            int newBlue = round((0.272 * orgRed) + (0.534 * orgGreen) + (0.131 * orgBlue));

            if (newBlue > 255.0)
            {
                image[i][j].rgbtBlue = 255.0;
            }
            else
            {
                image[i][j].rgbtBlue = newBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //zrobić kopie tego co go zaraz zamienie (image[i][j])
            RGBTRIPLE im_copy = image[i][j];
            image[i][j] = image[i][width - j - 1];
            //wstawić kopie
            image[i][width - j - 1] = im_copy;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE im_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            im_copy[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int xr = im_copy[i][j].rgbtRed;
            int xb = im_copy[i][j].rgbtBlue;
            int xg = im_copy[i][j].rgbtGreen;

            int ar = im_copy[i-1][j-1].rgbtRed;
            int br = im_copy[i-1][j].rgbtRed;
            int cr = im_copy[i-1][j+1].rgbtRed;
            int dr = im_copy[i][j-1].rgbtRed;
            int er = im_copy[i][j+1].rgbtRed;
            int fr = im_copy[i+1][j-1].rgbtRed;
            int gr = im_copy[i+1][j].rgbtRed;
            int hr = im_copy[i+1][j+1].rgbtRed;

            int ab = im_copy[i-1][j-1].rgbtBlue;
            int bb = im_copy[i-1][j].rgbtBlue;
            int cb = im_copy[i-1][j+1].rgbtBlue;
            int db = im_copy[i][j-1].rgbtBlue;
            int eb = im_copy[i][j+1].rgbtBlue;
            int fb = im_copy[i+1][j-1].rgbtBlue;
            int gb = im_copy[i+1][j].rgbtBlue;
            int hb = im_copy[i+1][j+1].rgbtBlue;

            int ag = im_copy[i-1][j-1].rgbtGreen;
            int bg = im_copy[i-1][j].rgbtGreen;
            int cg = im_copy[i-1][j+1].rgbtGreen;
            int dg = im_copy[i][j-1].rgbtGreen;
            int eg = im_copy[i][j+1].rgbtGreen;
            int fg = im_copy[i+1][j-1].rgbtGreen;
            int gg = im_copy[i+1][j].rgbtGreen;
            int hg = im_copy[i+1][j+1].rgbtGreen;

            //dla górnej kr
            if (i == 0) //&& j != 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((xr + dr + er + fr + gr + hr) / 6);
                image[i][j].rgbtGreen = round((xg + dg + eg + fg + gg + hg) / 6);
                image[i][j].rgbtBlue = round((xb + db + eb + fb + gb + hb) / 6);
            }
            //dla dolnej kr
            else if (i == height -1)
            {
                image[i][j].rgbtRed = round((xr + ar + br + cr + dr + er) / 6);
                image[i][j].rgbtGreen = round((xg + ag + bg + cg + dg + eg) / 6);
                image[i][j].rgbtBlue = round((xb + ab + bb + cb + db + eb) / 6);
            }
            //dla lewej kr
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((xr + br + cr + er + gr + hr) / 6);
                image[i][j].rgbtGreen = round((xg + bg + cg + eg + gg + hg) / 6);
                image[i][j].rgbtBlue = round((xb + bb + cb + eb + gb + hb) / 6);
            }
            //dla prawej kr
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((xr + ar + br + dr + fr + gr) / 6);
                image[i][j].rgbtGreen = round((xg + ag + bg + dg + fg + gg) / 6);
                image[i][j].rgbtBlue = round((xb + ab + bb + db + fb + gb) / 6);
            }
            //dla lewego górnego rogu
            else if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((xr + er + gr + hr) / 4);
                image[i][j].rgbtGreen = round((xg + eg + gg + hg) / 4);
                image[i][j].rgbtBlue = round((xb + eb + gb + hb) / 4);
            }
            //dla prawego górnego rogu
            else if (i == 0 && j == width -1)
            {
                image[i][j].rgbtRed = round((xr + dr + fr + gr) / 4);
                image[i][j].rgbtGreen = round((xg + dg + fg + gg) / 4);
                image[i][j].rgbtBlue = round((xb + db + fb + gb) / 4);
            }
            //dla lewego dolnego rogu
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((xr + br + cr + er) / 4);
                image[i][j].rgbtGreen = round((xg + bg + cg + eg) / 4);
                image[i][j].rgbtBlue = round((xb + bb + cb + eb) / 4);
            }
            //dla prawego dolnego rogu
            else if (i == height - 1 && j == width -1)
            {
                image[i][j].rgbtRed = round((xr + ar + br + dr) / 4);
                image[i][j].rgbtGreen = round((xg + ag + bg + dg) / 4);
                image[i][j].rgbtBlue = round((xb + ab + bb + db) / 4);
            }

            else
            {
                image[i][j].rgbtRed = round((xr + ar + br + cr + dr + er + fr + gr + hr) / 9);
                image[i][j].rgbtBlue = round((xb + ab + bb + cb + db + eb + fb + gb + hb) / 9);
                image[i][j].rgbtGreen = round((xg + ag + bg + cg + dg + eg + fg + gg + hg) / 9);
            }
        }
    }
    return;
}

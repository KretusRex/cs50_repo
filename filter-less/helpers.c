#include "helpers.h"
#include <cs50.h>
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                RGBTRIPLE *pixel = &image[i][j];
                float tmp;

                tmp = round((float)(pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue) / 3);

                pixel->rgbtBlue = pixel->rgbtGreen = pixel->rgbtRed = tmp;
            }
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
            RGBTRIPLE *pixel = &image[i][j];
            int tmp_red = round((pixel->rgbtRed * 0.393) + (pixel->rgbtGreen * 0.769) + (pixel->rgbtBlue * 0.189));
            int tmp_green = round((pixel->rgbtRed * 0.349) + (pixel->rgbtGreen * 0.686) + (pixel->rgbtBlue * 0.168));
            int tmp_blue = round((pixel->rgbtRed * 0.272) + (pixel->rgbtGreen * 0.534) + (pixel->rgbtBlue * 0.131));
            if (tmp_red < 256)
            {
                pixel->rgbtRed = tmp_red;
            }
            else
            {
                pixel->rgbtRed = 255;
            }
            if (tmp_green < 256)
            {
                pixel->rgbtGreen = tmp_green;
            }
            else
            {
                pixel->rgbtGreen = 255;
            }
            if (tmp_blue < 256)
            {
                pixel->rgbtBlue = tmp_blue;
            }
            else
            {
                pixel->rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE swap;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE *read_pixel = &image[i][j];
            RGBTRIPLE *write_pixel = &image[i][width - j - 1];
            swap = *read_pixel;
            *read_pixel = *write_pixel;
            *write_pixel = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create copy of an image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // code for copying ends here
    RGBTRIPLE read[9];
    RGBTRIPLE write;
    RGBTRIPLE average;

    for (int i = 0; i < height; i++) // iterating through height
    {

        for (int j = 0; j < width; j++) // iterating through width
        {
            int divider = 0;
            int k = 0;
            for (int v = 0; v < divider; v++)
            {
                read[v].rgbtRed = 0;
                read[v].rgbtGreen = 0;
                read[v].rgbtBlue = 0;
            }
            // i am not going to recode it into loops. NOT A CHANCE.
            // ALTHOUGH IT IS KIND OF TEMPTING
            // for (int l = -1; l < 2; l++) // vertical surrounding
            //{

            // for (int m = -1; m < 2; m++) // horizontal surrounding
            //{
            {
                if (i == 0 && j > 0 && j < width - 1) // top edge
                {
                    read[0] = copy[i + 1][j + 1];
                    read[1] = copy[i + 1][j];
                    read[2] = copy[i + 1][j - 1];
                    read[3] = copy[i][j + 1];
                    read[4] = copy[i][j];
                    read[5] = copy[i][j - 1];
                    divider = 6;
                    // printf("top edge\n");
                }
                else if (i == height - 1 && j > 0 && j < width - 1) // bottom edge
                {
                    read[0] = copy[i - 1][j + 1];
                    read[1] = copy[i - 1][j];
                    read[2] = copy[i - 1][j - 1];
                    read[3] = copy[i][j + 1];
                    read[4] = copy[i][j];
                    read[5] = copy[i][j - 1];
                    divider = 6;
                    // printf("bottom edge\n");
                }
                else if (i > 0 && i < height - 1 && j == 0) // left edge
                {
                    read[0] = copy[i - 1][j];
                    read[1] = copy[i][j];
                    read[2] = copy[i + 1][j];
                    read[3] = copy[i - 1][j + 1];
                    read[4] = copy[i][j + 1];
                    read[5] = copy[i + 1][j + 1];
                    divider = 6;
                    // printf("left edge \n");
                }
                else if (i > 0 && i < height - 1 && j == width - 1) // right edge // some sh%^ happened here
                {
                    read[0] = copy[i - 1][j];
                    read[1] = copy[i][j];
                    read[2] = copy[i + 1][j];
                    read[3] = copy[i - 1][j - 1];
                    read[4] = copy[i][j - 1];
                    read[5] = copy[i + 1][j - 1];
                    divider = 6;
                    // printf("right edge \n");
                }

                else if (i == height - 1 && j == width - 1) // bottom right
                {
                    read[0] = copy[i - 1][j - 1];
                    read[1] = copy[i - 1][j];
                    read[2] = copy[i][j - 1];
                    read[3] = copy[i][j];
                    divider = 4;
                    // printf("bottom right \n");
                }
                else if (i == height - 1 && j == 0) // bottom left
                {
                    read[0] = copy[i][j];
                    read[1] = copy[i][j + 1];
                    read[2] = copy[i - 1][j];
                    read[3] = copy[i - 1][j + 1];
                    divider = 4;
                    // printf("bottom left\n");
                }
                else if (i == 0 && j == width - 1) // upper right
                {
                    read[0] = copy[i][j];
                    read[1] = copy[i + 1][j];
                    read[2] = copy[i][j - 1];
                    read[3] = copy[i + 1][j - 1];
                    divider = 4;
                    // printf("upper right\n");
                }
                else if (i == 0 && j == 0) // upper left
                {
                    read[0] = copy[i + 1][j];
                    read[1] = copy[i + 1][j + 1];
                    read[2] = copy[i][j];
                    read[3] = copy[i][j + 1];
                    divider = 4;
                    // printf("upper left\n");
                }

                else if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
                {
                    // shitty code insert
                    read[0] = copy[i - 1][j - 1];
                    read[1] = copy[i - 1][j];
                    read[2] = copy[i - 1][j + 1];
                    read[3] = copy[i][j - 1];
                    read[4] = copy[i][j];
                    read[5] = copy[i][j + 1];
                    read[6] = copy[i + 1][j - 1];
                    read[7] = copy[i + 1][j];
                    read[8] = copy[i + 1][j + 1];
                    divider = 9;
                    /*read[k] = copy[i + l][j + m];
                    divider++;
                    k++;
                    //printf("inner\n");*/
                }
                int sumRed = 0;
                int sumGreen = 0;
                int sumBlue = 0;
                for (int v = 0; v < divider; v++)
                {
                    sumRed += read[v].rgbtRed;
                    sumGreen += read[v].rgbtGreen;
                    sumBlue += read[v].rgbtBlue;
                }
                average.rgbtRed = round((float) sumRed / divider);
                average.rgbtGreen = round((float) sumGreen / divider);
                average.rgbtBlue = round((float) sumBlue / divider);
                image[i][j] = average;
            }
            // }
            //}
        }
    }
    return;
}

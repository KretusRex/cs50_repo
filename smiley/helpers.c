#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            if (pixel->rgbtBlue == 0 && pixel->rgbtGreen == 0 && pixel->rgbtRed == 0)
            {
                pixel->rgbtBlue = 0xFF;
                pixel->rgbtGreen = 0xc0;
                pixel->rgbtRed = 0xBB;
            }
            // Now you can access pixel->rgbtBlue, pixel->rgbtGreen, and pixel->rgbtRed
        }
    }

    // Change all black pixels to a color of your choosing
}

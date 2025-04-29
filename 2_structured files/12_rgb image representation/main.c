#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    unsigned char red; // Red pixel intensity: 0-255
    unsigned char green; // Green pixel intensity: 0-255
    unsigned char blue; // Blue pixel intensity: 0-255
}RGBPixel;

int main()
{
    RGBPixel image[10][10];

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            image[i][j].red = (unsigned char)((255 / 10) * j);
            image[i][j].green = (unsigned char)((255 / 15) * j);
            image[i][j].blue = (unsigned char)((255 / 12) * j);
        }

    FILE* fp = fopen("image.bin", "wb");
    if(fp != NULL)
    {
        fwrite(image, sizeof(RGBPixel), 10 * 10, fp);
        fclose(fp);
    }
    return 0;
}

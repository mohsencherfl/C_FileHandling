#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    Point pointArr[5] = {{1,2},{3,4},{5,6},{7,8},{9,10}};
    FILE* fp = NULL;

    fp = fopen("myFile.bin", "wb");
    if(!fp)
    {
        printf("Failed to open the file. \n");
        return -1;
    }
    printf("File was successfully opened for binary writing. \n");

    // Option #1
    for(int i=0; i<5; i++)
    {
        fwrite(&pointArr[i], sizeof(Point), 1, fp);
    }

    // Option #2
    int writtenElements = fwrite(pointArr, sizeof(Point), 5, fp);
    printf("Successfully written Elements(Points): %d \n", writtenElements);

    fclose(fp);

    return 0;
}

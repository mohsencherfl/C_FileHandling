#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    Point p = {10,20};
    FILE* fp = NULL;

    fp = fopen("myFile.bin", "wb");
    if(!fp)
    {
        printf("Failed to open the file. \n");
        return -1;
    }
    printf("File was successfully opened for binary writing. \n");
    fwrite(&p, sizeof(Point), 1, fp);

    fclose(fp);

    return 0;
}

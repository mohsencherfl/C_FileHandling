#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

void readPoints(Point* p1, Point* p2, FILE* fp, int i)
{
    fseek(fp, i*sizeof(Point), SEEK_SET);
    fread(p1, sizeof(Point), 1, fp);
    fseek(fp, (-i-1)*sizeof(Point), SEEK_END);
    fread(p2, sizeof(Point), 1, fp);
}

void swapPoints(Point* p1, Point* p2, FILE* fp, int i)
{
    fseek(fp, i*sizeof(Point), SEEK_SET);
    fwrite(p2, sizeof(Point), 1, fp);
    fseek(fp, (-i-1)*sizeof(Point), SEEK_END);
    fwrite(p1, sizeof(Point), 1, fp);
}

void reversePointsOrder(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    Point p1, p2, temp;
    if(!fp)
    {
        printf("Failed to open the file! \n");
        return;
    }
    int n = 0;
    while(fread(&temp, sizeof(Point), 1, fp))
        n++;

    for(int i=0; i<n/2; i++)
    {
        readPoints(&p1, &p2, fp, i);
        swapPoints(&p1, &p2, fp, i);
    }

    fclose(fp);
}

int main()
{
    reversePointsOrder("myFile.bin");

    return 0;
}

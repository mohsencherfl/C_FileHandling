#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

void addPoint_firstApproach(char* filename, Point newPoint)
{
    FILE* fp = fopen(filename, "rb+");
    if(fp == NULL)
    {
        printf("Failed to open file. \n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(Point);

    Point* pointArray = (Point*)malloc( (totalPoints * sizeof(Point)) + (1 * sizeof(Point)) );

    fseek(fp, 0, SEEK_SET);
    fread(pointArray, sizeof(Point), totalPoints, fp);
    pointArray[totalPoints] = newPoint;

    fseek(fp, 0, SEEK_SET);
    fwrite(pointArray, sizeof(Point), totalPoints + 1, fp);

    fclose(fp);
    free(pointArray);
}

addPoint_secondApproach(char* filename, Point newPoint)
{
    FILE* fp = fopen(filename, "ab");
    if(fp == NULL)
    {
        printf("Failed to open file. \n");
        return;
    }

    fwrite(&newPoint, sizeof(Point), 1, fp);

    fclose(fp);
}

int main()
{
    Point p1 = {9, 10};
    Point p2 = {11, 12};
    addPoint_firstApproach("myFile.bin", p1);
    addPoint_secondApproach("myFile.bin", p2);

    return 0;
}

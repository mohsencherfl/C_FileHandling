#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

void reversePointsOrder(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if(!fp)
    {
        printf("Failed to open the file! \n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(Point);

    Point* pointArray = (Point*)malloc(totalPoints * sizeof(Point));

    fseek(fp, 0, SEEK_SET);
    fread(pointArray, sizeof(Point), totalPoints, fp);

    for(int i=0; i<totalPoints/2; i++)
    {
        Point temp = pointArray[i];
        pointArray[i] = pointArray[totalPoints-i-1];
        pointArray[totalPoints-i-1] = temp;
    }

    fseek(fp, 0, SEEK_SET);
    fwrite(pointArray, sizeof(Point), totalPoints, fp);

    free(pointArray);
    fclose(fp);
}

int main()
{
    reversePointsOrder("myFile.bin");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    int pointNum = 1;
    int pointFound = 0;
    FILE* fp = NULL;
    fp = fopen("myFile.bin", "rb");

    Point targetPoint;  // The point we are looking for
    Point pointInFile;  // The point we will read from the file

    printf("What is the point you are looking for? \n");
    printf("Enter x: ");
    scanf("%d", &targetPoint.x);
    printf("Enter y: ");
    scanf("%d", &targetPoint.y);

    if(!fp)
    {
        printf("Failed to open the file. \n");
        return -1;
    }

    while(!feof(fp))
    {
        fread(&pointInFile, sizeof(Point), 1, fp);
        if((pointInFile.x == targetPoint.x) && (pointInFile.y == targetPoint.y))
        {
            printf("Your point was found in the file. \n");
            printf("Point number in file: %d \n", pointNum);
            pointFound = 1;
            break;
        }
        pointNum++;
    }
    if(pointFound == 0)
        printf("No point was found! \n");

    fclose(fp);

    return 0;
}

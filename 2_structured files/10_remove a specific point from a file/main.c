#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

int checkUserInput(int* pNum, int totalPoints)
{
    printf("Which point do you want to remove? (1-%d): ", totalPoints);
    while(scanf("%d", pNum) != 1)
    {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n');  // Clears the buffer
    }

    while(*pNum > totalPoints || *pNum < 0)
    {
        printf("Enter a number that is within the specified range (1-%d)-(Enter 0 to exit): ", totalPoints);

        while(scanf("%d", pNum) != 1)
        {
            printf("Invalid input. Please enter an integer: ");
            while (getchar() != '\n');  // Clears the buffer
        }

        if(*pNum == 0)
        {
            printf("You decided not to delete any of the points. \n");
            return;
        }
    }

    if(*pNum == 0)
    {
        printf("You decided not to delete any of the points. \n");
        return;
    }
}

void removeSpecificPoint(char* filename, int* pNum)
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Failed to open file for reading. \n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(Point);

    if(totalPoints > 1)
    {
        checkUserInput(pNum, totalPoints);
        if(*pNum == 0)
            return;
        Point* pointArray = (Point*)malloc( (totalPoints * sizeof(Point)) - (1 * sizeof(Point)) );

        fseek(fp, 0, SEEK_SET);
        fread(&pointArray[0], sizeof(Point), *pNum-1, fp);
        fseek(fp, sizeof(Point), SEEK_CUR);
        fread(&pointArray[*pNum-1], sizeof(Point), totalPoints-*pNum, fp);

        fclose(fp);

        fp = fopen(filename, "wb");
        if(fp == NULL)
        {
            printf("Failed to open file for writing. \n");
            return;
        }

        fwrite(pointArray, sizeof(Point), totalPoints-1, fp);

        fclose(fp);
        free(pointArray);
    }
    else if(totalPoints == 1)
    {
        checkUserInput(pNum, totalPoints);
        if(*pNum == 0)
            return;
        fp = fopen(filename, "wb");
        if(fp == NULL)
        {
            printf("Failed to open file for writing. \n");
            return;
        }
        Point p0;
        fwrite(&p0, sizeof(Point), 0, fp);
        fclose(fp);
    }
    else
        printf("The file is empty. \n");
}

int main()
{
    int pointNum;
    removeSpecificPoint("myFile.bin", &pointNum);

    return 0;
}


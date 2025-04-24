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

void removeSpecificPoint(char* filename)
{
    FILE* fp = fopen(filename, "rb");
    FILE* temp = fopen("temp.bin", "wb");
    if(!fp || !temp)
    {
        printf("Failed to open the file. \n");
        return;
    }
    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(Point);
    if(totalPoints >= 1)
    {
        int pNum;
        checkUserInput(&pNum, totalPoints);
        if(pNum == 0)
        {
            fclose(fp);
            fclose(temp);
            remove("temp.bin");
            return;
        }

        Point* pTemp = (Point*)malloc(sizeof(Point));
        if(!pTemp)
        {
            printf("Memory allocation failed. \n");
            return;
        }
        fseek(fp, 0, SEEK_SET);
        for(int i=1; i<=totalPoints; i++)
        {
            if(i == pNum)
            {
                fseek(fp, sizeof(Point), SEEK_CUR);
                continue;
            }
            fread(pTemp, sizeof(Point), 1, fp);
            fwrite(pTemp, sizeof(Point), 1, temp);
        }
        fclose(fp);
        fclose(temp);
        free(pTemp);
        remove("myFile.bin");
        rename("temp.bin", "myFile.bin");
    }
    else
    {
        printf("The file is empty. \n");
        fclose(fp);
        fclose(temp);
    }
}

int main()
{
    removeSpecificPoint("myFile.bin");

    return 0;
}

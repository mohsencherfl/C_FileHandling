#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    int choice;
    Point m_point;

    printf("What is the point you would like to edit? (1-5) \n");
    scanf("%d", &choice);

    FILE* fp = NULL;
    fp = fopen("myFile.bin", "rb+");


    if(!fp)
    {
        printf("Failed to open the file. \n");
        return -1;
    }

    // Navigate to relevant address of the specific point in the file
    fseek(fp, (choice-1)*sizeof(Point), SEEK_SET);
    printf("The point has been located in the file... \n");

    // Enter new coordinations for the point
    printf("Enter new x: ");
    scanf("%d", &m_point.x);
    printf("Enter new y: ");
    scanf("%d", &m_point.y);

    // Update the record
    fwrite(&m_point, sizeof(Point), 1, fp);

    fclose(fp);

    return 0;
}

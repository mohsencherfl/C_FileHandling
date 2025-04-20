#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

void mulPointBy3(char* filename, unsigned int choice)
{
    FILE* fp = fopen(filename, "rb+");
    Point m_point;
    if(!fp)
    {
        printf("Failed to open the file! \n");
        return;
    }
    fseek(fp, (choice-1)*sizeof(Point), SEEK_SET);
    fread(&m_point, sizeof(Point), 1, fp);
    m_point.x *= 3;
    m_point.y *= 3;
//    fseek(fp, (choice-1)*sizeof(Point), SEEK_SET);
    fseek(fp, -1*sizeof(Point), SEEK_CUR);
    fwrite(&m_point, sizeof(Point), 1, fp);

    fclose(fp);
}

int main()
{
    int choice;
    char filename[50];

    printf("What is the point you would like to multiply by 3? (1-5) \n");
    scanf("%d", &choice);
    printf("Enter the file name: ");
    scanf("%s", &filename);

    mulPointBy3(filename, choice);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pos;
    FILE* fp = fopen("myfile.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    pos = ftell(fp);
    printf("Initial position in the file = %d \n", pos);
    fgetc(fp);
    pos = ftell(fp);
    printf("After reading one character, position = %d \n", pos);

    if(fseek(fp, -3, SEEK_END) != 0)
        perror("Error seeking in file");
    else
    {
        pos = ftell(fp);
        printf("The selected position in the file = %d \n", pos);
    }

    rewind(fp);
    pos = ftell(fp);
    printf("After rewinding, position = %d \n", pos);

    fclose(fp);

    return 0;
}

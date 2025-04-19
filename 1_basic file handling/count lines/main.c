#include <stdio.h>
#include <stdlib.h>

int main()
{
    int totalLines = 0;
    char character;

    FILE *file = fopen("output.txt", "r");

    if(file != NULL)
    {
        while((character = fgetc(file)) != EOF)
        {
            if(character == '\n')
                totalLines++;
        }
        totalLines++;   // Count the last missing line.
        fclose(file);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    printf("Total number of lines in the file is = %d \n", totalLines);

    return 0;
}

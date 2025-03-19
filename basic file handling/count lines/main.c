#include <stdio.h>
#include <stdlib.h>

int main()
{
    int characterCount = 0;
    char character;

    FILE *file = fopen("output.txt", "r");

    if(file != NULL)
    {
        while((character = fgetc(file)) != EOF)
        {
            if(character == '\n')
                characterCount++;
        }
        characterCount++;   // Count the last missing line.
        fclose(file);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    printf("Total number of lines in the file is = %d \n", characterCount);

    return 0;
}

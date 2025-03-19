#include <stdio.h>
#include <stdlib.h>

int main()
{
    int characterCount = 0;
    char character;

    FILE *file = fopen("myFile.txt", "r");

    if(file != NULL)
    {
        while((character = fgetc(file)) != EOF)
        {
            printf("%c", character);
            if(character == '\n')
                continue;
            characterCount++;
        }
        fclose(file);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    printf("\nTotal number of characters in the file is = %d \n", characterCount);
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char myChar, userChar;
    char fileName[30];
    int letterCount = 0;

    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the letter: ");
    scanf(" %c", &userChar);    // Space before the specifier ensures the leftover newline from the previous scanf() function is consumed, or we can use getchar() function after the previous scanf() function.

    FILE *file = fopen(fileName, "r");

    if(file != NULL)
    {
        while((myChar=fgetc(file)) != EOF)
        {
            if(myChar == userChar)
                letterCount++;
        }
        fclose(file);
        printf("Total number of appearances for letter (%c) is = %d \n", userChar, letterCount);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    char myChar;
    char fileName[30];
    int letterCount[26] = {0};  // Initialize the counter array to prevent automatic assignment of garbage values.

    printf("Enter the file name: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");

    if(file != NULL)
    {
/*
        while((myChar=fgetc(file)) != EOF)      // First method
        {
            if(myChar >= 'a' && myChar <= 'z')
            {
                letterCount[myChar - 'a']++;
            }
        }
*/
        while(!feof(file))      // Second method
        {
            myChar = fgetc(file);
            if(myChar >= 'a' && myChar <= 'z')
            {
                letterCount[myChar - 'a']++;
            }
        }
        fclose(file);

        for(int index=0; index<26; index++)
        {
            printf("Total appearances for letter (%c) = %d \n", index+'a', letterCount[index]);
        }
    }
    else
    {
        printf("Error! File failed to open.");
    }

    return 0;
}

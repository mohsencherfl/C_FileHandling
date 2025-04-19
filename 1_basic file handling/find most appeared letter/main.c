
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char myChar;
    char fileName[30];
    int letterCount[26] = {0};  // Initialize the counter array to prevent automatic assignment of garbage values.
    int maxIndex = letterCount[0];

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
            if(letterCount[index] > letterCount[maxIndex])
                maxIndex = index;
        }
                printf("The most appeared letter = %c (%d times appeared) \n", maxIndex+'a', letterCount[maxIndex]);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    return 0;
}

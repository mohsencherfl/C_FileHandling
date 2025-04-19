#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[100], extension[10], newfilename[110];
    int i, j;
    int result;

    printf("Enter the current file name with extension: ");
    scanf("%s", filename);  // newfile.txt

    printf("Enter the new extension for the file: ");
    scanf("%s", extension); // csv

    int dotPosition = -1;
    for(i=0; filename[i] != '\0'; i++)
    {
        if(filename[i] == '.')
        {
            dotPosition = i;
        }
    }

    if(dotPosition == -1)
    {
        printf("Error: filename does not have an extension. \n");
        return -1;
    }

    for(j=0; j<dotPosition; j++)
    {
        newfilename[j] = filename[j];
    }
    newfilename[dotPosition] = '.';

    for(i=0; extension[i] != '\0'; i++)
    {
        newfilename[++dotPosition] = extension[i];
    }
    newfilename[++dotPosition] = '\0';

    result = rename(filename, newfilename);
    if(result == 0)
        printf("File has been successfully renamed to %s \n", newfilename);
    else
        printf("Failed to rename file! \n");
}

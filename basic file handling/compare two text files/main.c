#include <stdio.h>
#include <stdlib.h>

int compareFiles(char* file1, char* file2)
{
    char currChar1, currChar2;
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if(fp1 == NULL)
    {
        printf("Failed to open file1... \n");
        return -1;
    }
    if(fp2 == NULL)
    {
        printf("Failed to open file2... \n");
        fclose(fp1);
        return -1;
    }

    currChar1 = fgetc(fp1);
    currChar2 = fgetc(fp2);

    while(currChar1 != EOF && currChar2 != EOF && currChar1 == currChar2)
    {
        currChar1 = fgetc(fp1);
        currChar2 = fgetc(fp2);
    }

    fclose(fp1);
    fclose(fp2);

    if(currChar1 == currChar2)
        return 1;
    else
        return 0;
}

int main()
{
    int result;
    result = compareFiles("myfile1.txt", "myfile2.txt");

    if(result == 1)
        printf("The two texts are identical. \n");
    else if(result == 0)
        printf("The two texts are not identical. \n");

    return 0;
}

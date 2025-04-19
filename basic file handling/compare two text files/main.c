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

void compareFiles_secondApproach(char* file1, char* file2)
{
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");
    char currChar1, currChar2;
    int mismatchIndex = 0;

    if(fp1 == NULL)
    {
        printf("Failed to open file1... \n");
        return;
    }
    if(fp2 == NULL)
    {
        printf("Failed to open file2... \n");
        fclose(fp1);
        return;
    }

    while(1)
    {
        currChar1 = getc(fp1);
        currChar2 = getc(fp2);

        if(currChar1 == EOF || currChar2 == EOF)
            break;
        if(currChar1 != currChar2)
        {
            printf("Found character mismatch at index: %d \n", mismatchIndex);
            fclose(fp1);
            fclose(fp2);
            return;
        }
        mismatchIndex++;
    }

    fclose(fp1);
    fclose(fp2);

    if(currChar1 == EOF && currChar2 == EOF)
    {
        printf("Both files reached EOF simultaneously, so they must be identical. \n");
        return;
    }
    else
    {
        printf("One of the files reached EOF, so they are not identical. \n");
        return;
    }
}


int main()
{
    int result;
    result = compareFiles("myfile1.txt", "myfile2.txt");
    compareFiles_secondApproach("myfile1.txt", "myfile2.txt");

    if(result == 1)
        printf("The two texts are identical. \n");
    else if(result == 0)
        printf("The two texts are not identical. \n");

    return 0;
}

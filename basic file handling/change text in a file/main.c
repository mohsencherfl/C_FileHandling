#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp1 = fopen("myfile.txt", "r");
    FILE* fp2 = fopen("tempfile.txt", "w");
    char word[50];

    if(fp1 == NULL || fp2 == NULL)
        return -1;

    while(fscanf(fp1, "%s", &word) != EOF)
    {
        if(strcmp(word, "Germany") == 0)
        {
            strcpy(word, "Iran");
        }
        fprintf(fp2, "%s", word);

        char nextChar = fgetc(fp1);
        if(nextChar == '\n')
        {
            fprintf(fp2, "\n");
        }
        else if(nextChar != EOF)
        {
            fprintf(fp2, " ");
            ungetc(nextChar, fp1);
        }
    }

    fclose(fp1);
    fclose(fp2);

    remove("myfile.txt");
    rename("tempfile.txt", "myfile.txt");

    printf("The word Germany has been replaced. \n");

    return 0;
}

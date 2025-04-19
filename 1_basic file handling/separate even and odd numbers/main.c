#include <stdio.h>
#include <stdlib.h>

void separateEvenOddNumbers(char* inputFilename)
{
    FILE* sourceFP = NULL;
    FILE* evenFP = NULL;
    FILE* oddFP = NULL;

    int num;

    sourceFP = fopen(inputFilename, "r");
    if(sourceFP == NULL)
    {
        printf("Couldn't open the file... \n");
        exit(-1);
    }

    evenFP = fopen("even.txt", "w");
    oddFP = fopen("odd.txt", "w");
    if(evenFP == NULL)
    {
        printf("Couldn't open the file for even numbers... \n");
        exit(-1);
    }
    if(oddFP == NULL)
    {
        printf("Couldn't open the file for odd numbers... \n");
        exit(-1);
    }

    while(fscanf(sourceFP, "%d", &num) != EOF)
    {
        if(num % 2 == 0)
            fprintf(evenFP, "%d ", num);
        else
            fprintf(oddFP, "%d ", num);
    }

    fclose(sourceFP);
    fclose(evenFP);
    fclose(oddFP);
}

int main()
{
    char inputFilename[50];
    printf("Enter input filename: ");
    scanf("%s", inputFilename);

    separateEvenOddNumbers(inputFilename);

    return 0;
}

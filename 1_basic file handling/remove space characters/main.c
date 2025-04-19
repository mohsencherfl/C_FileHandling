#include <stdio.h>
#include <stdlib.h>

void removeSpaceCharacters(char* inputFilename, char* outputFilename)
{
    char currentCharacter;
    FILE* inFile = fopen(inputFilename, "r");
    FILE* outFile = fopen(outputFilename, "w");
    if(inFile != NULL && outFile != NULL)
    {
        while((currentCharacter = fgetc(inFile)) != EOF)
        {
            if(currentCharacter != ' ')
                fputc(currentCharacter, outFile);
        }
    }
    if(inFile != NULL)
        fclose(inFile);
    if(outFile)
        fclose(outFile);
}

int main()
{
    char input_filename[50];
    char output_filename[50];

    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    removeSpaceCharacters(input_filename, output_filename);

    return 0;
}

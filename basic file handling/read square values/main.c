#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
    char myChar1, myChar2;

    FILE *file = fopen("output.txt", "r");

    if(file != NULL)
    {
        for(int i=1; i<=10; i++)    // Assuming there are only ten lines in the file
        {
            fscanf(file, "%d %c %d %c %d", &num1, &myChar1, &num2, &myChar2, &num3);    // Be sure of your data format in the file
            printf("%d * %d = %d \n", num1, num2, num3);
        }
        fclose(file);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    return 0;
}

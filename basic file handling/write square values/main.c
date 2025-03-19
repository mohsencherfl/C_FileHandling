#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("output.txt", "w");

    if(file != NULL)
    {
        for(int i=1; i<=10; i++)
        {
            fprintf(file, "%d * %d = %d \n", i, i, i*i);
        }
        fclose(file);
    }
    else
    {
        printf("Error! File failed to open.");
    }

    return 0;
}

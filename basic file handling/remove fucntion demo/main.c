#include <stdio.h>

int main() {

    FILE* file = fopen("test.txt", "w");
    if(file == NULL)
    {
        printf("Failed to open file! \n");
        return 1;
    }

    fprintf(file, "User input string.... \n");

    fclose(file);

    if(remove("test.txt") != 0)
        printf("Failed to delete the file. \n");
    else
        printf("File was deleted successfully. \n");

    return 0;
}


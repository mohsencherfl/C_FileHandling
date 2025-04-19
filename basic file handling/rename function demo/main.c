#include <stdio.h>

int main()
{
    int result;
    result = rename("oldfile.txt", "newfile.txt");
    if(result == 0)
        printf("File has been renamed successfully. \n");
    else
        printf("Rename did not work! \n");

    result = rename("newfile.txt", "../../newFolder/movedFile.txt");
    if(result == 0)
        printf("File has been moved successfully. \n");
    else
        printf("Move did not work! \n");
}

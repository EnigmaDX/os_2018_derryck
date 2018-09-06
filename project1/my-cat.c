#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) 
{
    //loop through arguments for file names
    for(int i=1; i<argc; i++)
    {
         char * fileName = argv[i];
         
        FILE *file = fopen(fileName, "r");

        char string [100];
        char *readLine;

        if (file == NULL) 
        {
            perror("my-cat: cannot open file \n");
            return(1);
        }
        else 
        {
            // printf("\n__\n \n");
            while((readLine = fgets(string, 100, file)) != NULL)
            {
                printf("%s", readLine);
            }
        }
        fclose(file);
    }//end of for loop

    return 0;
}
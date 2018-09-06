#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) 
{
    //loop through arguments for file names
    for(int i=1; i<argc; i++)
    {
         char * fileName = argv[i];
         printf("\n File name is %s \n---------------------\n", fileName);
         
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
            while((readLine = fgets(string, 100, file)) != NULL)
            {
                printf("%s", readLine);
            }
            printf("\n---------------------------\n");
        }
        fclose(file);
    }//end of for loop

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    const char *fileName;
    FILE *file;
    char *mBuffer = NULL;
    ssize_t readLine;
    size_t len = 1000;
    char input [100];

    //1 no arguments passed
    if(argc < 2) 
    {
        printf("my-grep: searchterm [file ...] \n");
        exit(1);
    }

    //2 if search term is provided but no file specified
    else if(argc < 3) 
            {
                fgets(input,50,stdin);
                printf("%s \n", input);
                exit(1);
            }
    // search term and one or more files provided
    else
    {
        for(int i = 2; i < argc; i++)
        {
            fileName = argv[i];
            file = fopen(fileName, "r");

            if (file == NULL) 
            {
                perror("my-grep: cannot open file \n");
                return(1);
            }
            else 
            {
                printf("Scanning for (%s)... \n", argv[1]);
                while((readLine = getline(&mBuffer,&len,file)) != -1)
                    {
                        if(strstr(mBuffer, argv[1]) != NULL)
                        {
                            printf("%s \n", mBuffer);
                        }
                    }
            }
        }
    }
    
        // fclose(file);
    return 0;
}

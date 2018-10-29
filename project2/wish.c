#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) 
{
    char *input;
    size_t bufsize = 32;
    size_t characters;

    input = (char *)malloc(bufsize * sizeof(char));
    if(input == NULL)
    {
        perror("Unable to allocate input");
        // exit(1);
    }
    
    
    if(argc == 1)
    {
        while(1)
        {
            printf("wish> ");
            getline(&input,&bufsize,stdin);
            printf("Line: %s",input);

            char *strarray = input;
            char *token;
            token = strtok(strarray, " ");
   
  
            while(token != NULL)
            {
                printf(" %s\n", token);
                token = strtok(NULL, " "); 
            }

            if(strstr(input, "exit"))
            {
                printf("I'm exitiing....\n");
                exit(0);
            }
        }
    }


    return 0;
}







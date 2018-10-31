#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char * argv[]) 
{
    char *input;
    size_t bufsize = 32;
    size_t characters;
    char *path = "/bin";

    input = (char *)malloc(bufsize * sizeof(char));
    if(input == NULL)
    {
        perror("Unable to allocate input");
        // exit(1);
    }
    
    
    //INTERACTIVE MODE
    if(argc == 1)
    {
        while(1)
        {
            printf("wish>");
            getline(&input,&bufsize,stdin);
            int strlength = strlen(input);
            strtok(input, "\n");

            char *strarray = input;
            char *token;
            token = strtok(strarray, " ");

            char *commands[10];
            int commandCount = 0;
  
            while(token != NULL)
            {
                // printf(" %s\n", token); 
                commands[commandCount] = token;
                commandCount++;
                token = strtok(NULL, " ");
            }

            // printf("commandCount: %d \n", commandCount);

            // for(int i=0; i<commandCount; i++)
            // {
            //     printf("token at %d is: %s \n", i, commands[i]);
            // }

            //exit
            if((strcmp(commands[0], "exit")) == 0)
            {
                printf("I'm exitiing....\n");
                exit(0);
            }

            //path
            else if((strcmp(commands[0], "path")) == 0)
            {
                //
                pid_t checkPath = fork();
                if(checkPath < 0)
                {
                    fprintf(stderr, "fork failed\n");
                }

                else if(checkPath == 0)
                {
                    printf("pid: %d \n", (int)getpid);
                    strcat(path,commands[1]); 
                    printf("init path: %s", path);  
                    if(access(path, X_OK))
                    {

                    }
                }
                else
                {
                    // int checkPath_wait = wait(NULL);
                    printf("no path created, fork value: %d \n", checkPath);
                }
                 
                

            }

            //cd
            else if((strcmp(commands[0], "cd")) == 0)
            {
                char *dir = strtok(commands[1], "\n");
                if(chdir(dir) == 0)
                {
                    printf("in new dir \n");
                }
                else
                {
                    printf("Error changing new dir \n");
                }
                
            }
            else
            {
                printf("Say Something!! \n");
            }
        }//end of while
    }


    return 0;
}







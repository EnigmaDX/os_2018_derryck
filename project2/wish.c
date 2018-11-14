#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char * argv[]) 
{
    char *input;
    size_t bufsize = 32;
    size_t characters;
    char pathArray[10];
    strcpy(pathArray, "/bin/");


    input = (char *)malloc(bufsize * sizeof(char));
    if(input == NULL)
    {
        perror("Unable to allocate input");
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
                commands[commandCount] = token;
                commandCount++;
                token = strtok(NULL, " ");
            }

            //exit command
            if((strcmp(commands[0], "exit")) == 0)
            {
                printf("I'm exitiing....\n");
                exit(0);
            }

            //path command
            else if((strcmp(commands[0], "path")) == 0)
            {
                if(commands[1] == NULL)
                {
                    printf("No path specified \n");
                }
                
                pid_t checkPath = fork();
                if(checkPath < 0)
                {
                    fprintf(stderr, "fork failed\n");
                }
                else if(checkPath == 0)
                {
                    printf("pid: %d \n", (int)getpid);

                    strcat(pathArray,commands[1]); 
                    printf("init path: %s \n", pathArray);  
                    if(access(pathArray, X_OK))
                    {
                        printf("Path Activated \n");
                        execv(commands[1], commands); 
                        printf("Working \n");
                    }
                    exit(0);
                }
                else
                {
                    int checkPath_wait = wait(NULL);
                    printf("path process done.. \n");
                }
                 
                

            }

            //cd command
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
            
            //other built-in commands
            else
            {
                int newProcess = fork();
                if(newProcess < 0)
                {
                    fprintf(stderr, "fork failed\n");
                }
                else if(newProcess == 0)
                {
                    execv(commands[0], commands);
                }
                else
                {
                    wait(NULL);
                }

            }
        }//end of while
    }


    return 0;
}







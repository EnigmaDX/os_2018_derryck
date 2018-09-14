#include <stdio.h>

int input(char *s,int length);

int main()
{

    FILE *file = fopen("main.c", "r");

    char buffer[32];
    char *b = buffer;
    size_t bufsize = 32;
    size_t characters;

    // printf("Type something: ");
    // while(characters)
    // {
        // characters = getline(&b,&bufsize,file);

    for(size_t i=0; i<bufsize; i++)
    {
        characters = getline(&b,&bufsize,file);
        printf("%s \n",buffer);
        // printf("%zu \n", characters);
    }


    // printf("%zu characters were read.\n",characters);

    return(0);
}
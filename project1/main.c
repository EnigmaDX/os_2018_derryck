#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char array1[6];
    int size = sizeof(array1) / sizeof(char);
    printf("Array Size is %d \n", size);

    return 0;

}
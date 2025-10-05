#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char* file_name){
    FILE* fileptr = fopen(file_name, "r");

    if(!fileptr){
        perror("file not found\n");
        exit(EXIT_FAILURE);
    }

    return fileptr;
}
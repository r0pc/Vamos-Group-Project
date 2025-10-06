#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_file_type(char* file_name){
    char* lastfour = file_name + (strlen(file_name) -4);

    if(strcmp(lastfour, ".txt")){
        
    }else if(strcmp(lastfour, ".csv")){

    }else{
        printf("invlaid file format : %s\n", file_name);
        exit(EXIT_FAILURE);
    }
}

FILE *open_file(char* file_name){
    FILE* fileptr = fopen(file_name, "r");

    if(!fileptr){
        perror("file not found\n");
        exit(EXIT_FAILURE);
    }

    return fileptr;
}

void file_process_txt(char* file_name){
    FILE* fileptr = open_file(file_name);
    char buff[256];
    while(fgets(buff, sizeof(buff), fileptr)){

    }
}

void file_process_csv(char* file_name){
    FILE* fileptr = open_file(file_name);
    char buff[256];
    fgets(buff, sizeof(buff), fileptr);

}
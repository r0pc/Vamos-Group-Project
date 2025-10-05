#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filing.h"



char** tokenize(char* s){
    unsigned int curr_capcity = 0;
    unsigned int curr_element = 0;

    char delimeter[] = " \n";
    char ** arr;
    char* token;

    token = strtok(s, delimeter);
    while(token){
        curr_capcity++;
        arr = (char**)realloc(arr, curr_capcity * sizeof(char*));
        arr[curr_element++] = strdup(token);
        token = strtok(NULL, delimeter);
    }
} 
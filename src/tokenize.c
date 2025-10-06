#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"


// takes in string and returns an arr.
// ex: "my name is rafay" -> ["my", "name", "is", "rafay"]

char** tokenize(char* s){
    unsigned int curr_capcity = 0;
    unsigned int curr_element = 0;

    char delimeter[] = " .,:;\"\'\n";
    char ** arr;
    char* token;

    token = strtok(s, delimeter);
    while(token){
        curr_capcity++;
        arr = (char**)realloc(arr, curr_capcity * sizeof(char*));
        arr[curr_element++] = strdup(token);
        token = strtok(NULL, delimeter);
    }

    return arr;
} 
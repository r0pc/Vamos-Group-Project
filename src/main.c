#include <stdio.h>
#include "tokenize.h"

int main(void){
    char buff [256];
    FILE* fileptr = fopen("test.txt", "r");
    while(fgets(buff, sizeof(buff), fileptr)){
        char** arr = tokenize(buff);

        
    }

    printf("helloworld\n");
    return 0;
}
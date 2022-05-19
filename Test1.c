#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "akagi.c"

typedef char String[1024];

int main(int argc, char** argv){
    printf("argc=%d\n", argc);
    for(int i = 0; i < argc; i++){
        char* strAddr = argv[i];
        printf("Number Information %d : %s\n", i, strAddr);
    }
    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

void NumberMulti10(int id, int *number){
    *number = (id + 1) * 10;
}

void DisplayID(int id, int number){
    printf("ID %d : %d\n", id, number);
}

int main(){ 
    int number[10];
    int lengthSize = sizeof(number) / sizeof(int);

    // for(int i = 0; i < lengthSize; i++){
    //     NumberMulti10(i, &number[i]);
    //     DisplayID(i, number[i]);
    // }
    
    for(int i = 0; i < lengthSize; i++){
        number[i] = (i + 1) * 10;
        printf("Number %d : %d\n", i, number[i]);
    }

    // for(int i = 0; i < lengthSize; i++){
    //     printf("Number %d : %d\n", i, (i + 1) * 10);
    // }

    return 0;
}
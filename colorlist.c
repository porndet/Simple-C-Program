#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

typedef struct listfruit
{
    char listfruit[50][100];
} listfruit;

typedef struct Colorlist
{
    String colour;
    int length;
    listfruit L1;
} Colorlist;


int main(void){
    Colorlist apple, banana;

    strcpy(apple.colour, "red");
    apple.length = 0;
    strcpy(banana.colour, "yellow");
    banana.length = 0;

    strcpy(apple.L1.listfruit[apple.length], "cherry");
    apple.length++;
    strcpy(apple.L1.listfruit[apple.length], "strawberry");
    apple.length++;
    strcpy(apple.L1.listfruit[apple.length], "apple");
    apple.length++;

    strcpy(banana.L1.listfruit[banana.length], "banana");
    banana.length++;

    // for(int i = 0; i < apple.length; i++){
    //     printf("%s", apple.L1.listfruit[i]);
    // }

    String colour;
    printf("input color > ");
    scanf("%s", colour);   
    if(strcmp(colour, apple.colour) == 0) {
        printf("%s/", apple.colour);
        for(int i = 0; i < apple.length; i++){
            if(i == apple.length - 1){
                printf("%s", apple.L1.listfruit[i]);
            }else{
                printf("%s,", apple.L1.listfruit[i]);
            }
        }
    }else if((strcmp(colour, banana.colour) == 0)){
        printf("%s/", banana.colour);
        for(int i = 0; i < banana.length; i++){
            if(i == banana.length - 1){
                printf("%s", banana.L1.listfruit[i]);
            }else{
                printf("%s,", banana.L1.listfruit[i]);
            }
        }        
    }else{
        printf("Sorry... %s is not color list.", colour);
    }
    
    return 0;
}
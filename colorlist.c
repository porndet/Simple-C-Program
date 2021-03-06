#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];
#define lengthArr 6

typedef struct listfruit
{
    char listfruit[50][100];
    int lengthfruit;
} listfruit;

typedef struct Colorlist
{
    String color;
    int lengthcolor;
    listfruit L1;
} Colorlist;

void PushcolorFruit(Colorlist *C, String color){
    strcpy(C->color, color);
}

void PushFruit(Colorlist *C, String fruit){
    strcpy(C->L1.listfruit[C->L1.lengthfruit], fruit);
    C->L1.lengthfruit++;
}

void Showcolorfruit(Colorlist *C){
    printf("%s\n", C->color);
}

void Showfruit(Colorlist *C){
    printf("%s/",C->color);
    for(int i = 0; i < C->L1.lengthfruit; i++){
        if(i == C->L1.lengthfruit - 1){
            printf("%s ", C->L1.listfruit[i]);
        }else{
            printf("%s,", C->L1.listfruit[i]);
        }
    }
}


int main(void){
    Colorlist fruitscolor[lengthArr];

    for(int i = 0; i < lengthArr; i++){
        fruitscolor[i].L1.lengthfruit = 0;
    }

    PushcolorFruit(&fruitscolor[0], "red");
    PushcolorFruit(&fruitscolor[1], "yellow");
    PushcolorFruit(&fruitscolor[2], "purple");
    PushcolorFruit(&fruitscolor[3], "green");
    PushcolorFruit(&fruitscolor[4], "orange");
    PushcolorFruit(&fruitscolor[5], "pink");

    PushFruit(&fruitscolor[0], "cherry");
    PushFruit(&fruitscolor[0], "strawberry");
    PushFruit(&fruitscolor[0], "apple");

    PushFruit(&fruitscolor[1], "banana");
    PushFruit(&fruitscolor[1], "pineapple");
    PushFruit(&fruitscolor[1], "grapefruits");

    PushFruit(&fruitscolor[2], "grape");

    PushFruit(&fruitscolor[3], "melon");

    PushFruit(&fruitscolor[4], "orange");

    PushFruit(&fruitscolor[5], "pink");

    String colour;
    bool isTrue = true;
    printf("input color > ");
    scanf("%s", colour);
    for(int i = 0; i < lengthArr && isTrue; i++){
        if(strcmp(colour, fruitscolor[i].color) == 0){
            Showfruit(&fruitscolor[i]);
            isTrue = false;
            break;
        }else{
            if(i == lengthArr - 1){
                isTrue= false;
                printf("Sorry... %s is not color list.", colour);
                break;
            }
        }
    }
    return 0;
}
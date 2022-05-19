#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define lengthArr 3
// #include "headerRensyuu7-4.h"

typedef char String[1024];

// void New_RandomThreeNumber(){
//     srand(time(NULL));
//     int number[3];
    
//     for(int i = 0; i < 3; i++){
//         int random = rand() % 10;
//         if(i == 0){
//             number[i] = random;
//         }else{
//             number[i] = random;
//             for(int j = 0; j < i; j++){
//                 while(number[i] == number[j]){
//                     random = rand() % 10;
//                     number[i] = random;
//                 }
//             }
//         }
//     }

//     for(int i = 0; i < 3; i++){
//         printf("%d ", number[i]);
//     }
// }

void printAnswer(int answer[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", answer[i]);
    }
}

void inputNum(int input[], int i){
    printf("(%d) Please put guess number 0~99 : ", i + 1);
    String inputStr;
    scanf("%s", inputStr);
    input[i] = atoi(inputStr);    
}

void getAnswer(int answer[], int i){
    bool check;
    do{
        answer[i] = rand() % 100;
        for(int j = 0; j < i; j++){
            check = false;
            if(answer[i] == answer[j]){
                break;
            }
            check = true;
        }
    }while(i > 0 && check == false);
}

typedef struct HitBlow{
    int hit;
    int blow;
} HitBlow;

void checkHitBlow(int answer[], int input[], HitBlow* hitblow){
    printf("-------- Result ---------\n");
    for(int i = 0; i < lengthArr; i++){
        if(input[i] == answer[i]){
            printf("No.%d : Correct\n", i + 1);
            hitblow->hit++;
        }else{
            if(input[i] > answer[i]){
                printf("No.%d : Big value\n", i + 1);
            }else{
                printf("No.%d : Less value\n", i + 1);
            }
        }
    }
}


int main() {
    //New_RandomThreeNumber();
    //mainFunction();

    srand(time(NULL));

    printf("*** Guess number game (Level 2) ***\n");
    printf("Please guess number correct in 3 number\n");
    printf("But each number will unique\n");

    const int TIMES = 3;
    int answer[lengthArr];
    int input[lengthArr], *ptrinput;
    bool check, isTrue = true;
    int retryStr;

    int lengthanswer = sizeof(answer) / sizeof(int);

    for(int i = 0; i < TIMES; i++){
        getAnswer(answer, i);
    }

    printAnswer(answer, lengthanswer);
    printf("\n");

    do{
        HitBlow hitblow;
        hitblow.hit = 0;
        hitblow.blow = 0;

        for(int i = 0; i < TIMES; i++){ 
            inputNum(input, i);
        }

        checkHitBlow(answer, input, &hitblow);

        if(hitblow.hit == 3){
            printf("All Correct\n");
            printf("--------------------------------\n");
            printf("Winner!!!\n");
            break;
        }else{
            while(isTrue){
                printf("Will play continue? (0:end  1:continue) : ");
                scanf("%d", &retryStr);
                if(retryStr == 1 || retryStr == 0){
                    isTrue = false;
                }
            }
            if(retryStr == 0){
                printf("Answer Correct ");
                printAnswer(answer, lengthanswer);
                break;
            }
            isTrue = true;
        }
    }while(true);
    
	return 0;
}
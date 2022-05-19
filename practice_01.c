#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

int CheckWin(char numberXO[]){
    if(numberXO[0] == numberXO[1] && numberXO[1] == numberXO[2]){
        //1 2 3
        if(numberXO[0] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[3] == numberXO[4] && numberXO[4] == numberXO[5]){
        //4 5 6
        if(numberXO[3] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[6] == numberXO[7] && numberXO[7] == numberXO[8]){
        //7 8 9
        if(numberXO[6] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[0] == numberXO[3] && numberXO[3] == numberXO[6]){
        //1 4 7
        if(numberXO[0] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[0] == numberXO[4] && numberXO[4] == numberXO[8]){
        //1 5 9
        if(numberXO[0] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[1] == numberXO[4] && numberXO[4] == numberXO[7]){
        //2 5 8
        if(numberXO[1] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[2] == numberXO[4] && numberXO[4] == numberXO[6]){
        //3 5 7
        if(numberXO[2] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[2] == numberXO[5] && numberXO[5] == numberXO[8]){
        //3 6 9
        if(numberXO[2] == 'o'){
            return 1;
        }else{
            return 2;
        }
    }else{
        return 0;
    }
}

void DisplayXOGame(char numberXO[]){
    printf("|%c|%c|%c|\n", numberXO[0], numberXO[1], numberXO[2]);
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", numberXO[3], numberXO[4], numberXO[5]);
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", numberXO[6], numberXO[7], numberXO[8]);
    printf("########\n");
}

int main(void){

    char numberXO[9] = {'1','2','3','4','5','6','7','8','9'};
    int player, computer;
    bool isPlayer, isComputer, isComplete = true;
    char Playername[10];

    do{
        printf("------Please put name player------\n>");
        scanf("%10s%*[^\n]", Playername);
        printf("------Player name : %s ------\n\n\n", Playername);
    }while(strncmp(Playername, "Computer", strlen("Computer")) == 0);
    
    srand(time(NULL));

    printf("### XO GAME ###\n");
    printf("+-+-+-+\n");
    while(isComplete){
        isPlayer = true;
        isComputer = true;
        DisplayXOGame(numberXO);

        while(isPlayer){
            printf("%s o Please select number : ", Playername);
            scanf("%d", &player);
            if(numberXO[player - 1] != 'o' && numberXO[player - 1] != 'x'){
                numberXO[player - 1] = 'o';
                isPlayer = false;
            }
        }

        printf("Comuter x Select number : ");
        while(isComputer){
            computer = rand() % 9 + 1;
            if(numberXO[computer - 1] != 'o' && numberXO[computer - 1] != 'x'){
                printf("%d\n", computer);
                numberXO[computer - 1] = 'x';
                isComputer = false;
            }
        }

        int checkWin = CheckWin(numberXO);

        if(checkWin == 1){
            DisplayXOGame(numberXO);
            printf("%s Win!!", Playername);
            isComplete = false;
        }else if(checkWin == 2){
            DisplayXOGame(numberXO);
            printf("Computer Win!!");
            isComplete = false;
        }else{
            
        }
    }
}
// #include <stdio.h>
// #include <time.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdint.h>

// typedef char String[1024];

// void DisplayXOGame(char numberXO[]){
//     printf("|%c|%c|%c|\n", numberXO[0], numberXO[1], numberXO[2]);
//     printf("+-+-+-+\n");
//     printf("|%c|%c|%c|\n", numberXO[3], numberXO[4], numberXO[5]);
//     printf("+-+-+-+\n");
//     printf("|%c|%c|%c|\n", numberXO[6], numberXO[7], numberXO[8]);
//     printf("########\n");
// }

// void CompleteGame(int win, char player[]){
//     if(win = 1){
//         printf("End Game : %s Win!\n", player);
//     }else{
//         printf("End Game : Computer Win!\n");
//     }
// }


// int main() {
//     char numberXO[9] = {'1','2','3','4','5','6','7','8','9'};
//     char Playername[10];
//     int player, computer, checkMark;
//     char mark;

//     do{
//         printf("------Please put name player------\n>");
//         scanf("%10s%*[^\n]", Playername);
//         printf("------Player name : %s ------\n\n", Playername);
//     }while(strncmp(Playername, "Computer", strlen("Computer")) == 0);

//     printf("------Please put player mark------\n");
//     printf("Mark to used #, $, %, &, @, A-Z , a-z\n");
//     scanf("%s", &mark);

//     checkMark = (int)mark;

//     if(!((checkMark >= 35 && checkMark <= 38) || checkMark == 64 || (checkMark >= 65 && checkMark <= 90) || (checkMark >= 97 && checkMark <= 122))){
//         printf("Error You put mark without to setting\n");
//         mark = 'o';        
//     }

//     printf("------ Mark of %s is %c ------\n", Playername, mark);

//     printf("### XO GAME ###\n");
//     printf("+-+-+-+\n");
    
//     DisplayXOGame(numberXO);

//     printf("------Turn %s ------\n", Playername);
//     printf("%s : o Plase select number : ", Playername);
//     scanf("%d", &player);

//     printf("------Turn Computer ------\n");
//     printf("Computer : x Plase select number : %d\n", rand() % 9 + 1);
    
//     CompleteGame(1, Playername);

// 	return 0;
// }

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

int CheckWin(char numberXO[], char mark){
    if(numberXO[0] == numberXO[1] && numberXO[1] == numberXO[2]){
        //1 2 3
        if(numberXO[0] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[3] == numberXO[4] && numberXO[4] == numberXO[5]){
        //4 5 6
        if(numberXO[3] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[6] == numberXO[7] && numberXO[7] == numberXO[8]){
        //7 8 9
        if(numberXO[6] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[0] == numberXO[3] && numberXO[3] == numberXO[6]){
        //1 4 7
        if(numberXO[0] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[0] == numberXO[4] && numberXO[4] == numberXO[8]){
        //1 5 9
        if(numberXO[0] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[1] == numberXO[4] && numberXO[4] == numberXO[7]){
        //2 5 8
        if(numberXO[1] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[2] == numberXO[4] && numberXO[4] == numberXO[6]){
        //3 5 7
        if(numberXO[2] == mark){
            return 1;
        }else{
            return 2;
        }
    }else if(numberXO[2] == numberXO[5] && numberXO[5] == numberXO[8]){
        //3 6 9
        if(numberXO[2] == mark){
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
    int player, computer, checkMark;
    bool isPlayer, isComputer, isComplete = true;
    char Playername[10], mark;
    String nameplayer;
    srand(time(NULL));

    do{
        printf("------Please put name player------\n>");
        scanf("%10s%*[^\n]", Playername);
        printf("------Player name : %s ------\n\n\n", Playername);
        strcpy(nameplayer, Playername);
    }while(strncmp(Playername, "Computer", strlen("Computer")) == 0);
    
    printf("------Please put player mark------\n");
    printf("Mark to used #, $, %, &, @, A-Z , a-z\n");
    scanf("%s", &mark);

    checkMark = (int)mark;

    if(!((checkMark >= 35 && checkMark <= 38) || checkMark == 64 || (checkMark >= 65 && checkMark <= 90) || (checkMark >= 97 && checkMark <= 122))){
        printf("Error You put mark without to setting\n");
        mark = 'o';        
    }

    printf("------ Mark of %s is %c ------\n", nameplayer, mark);

    printf("### XO GAME ###\n");
    printf("+-+-+-+\n");
    while(isComplete){
        isPlayer = true;
        isComputer = true;
        DisplayXOGame(numberXO);

        while(isPlayer){
            printf("%s %c Please select number : ", nameplayer, mark);
            scanf("%d", &player);
            if(numberXO[player - 1] != mark && numberXO[player - 1] != '*'){
                numberXO[player - 1] = mark;
                isPlayer = false;
            }
        }

        printf("Comuter * Select number : ");
        while(isComputer){
            computer = rand() % 9 + 1;
            if(numberXO[computer - 1] != mark && numberXO[computer - 1] != '*'){
                printf("%d\n", computer);
                numberXO[computer - 1] = '*';
                isComputer = false;
            }
        }

        int checkWin = CheckWin(numberXO, mark);

        if(checkWin == 1){
            DisplayXOGame(numberXO);
            printf("%s %c Win!!", nameplayer, mark);
            isComplete = false;
        }else if(checkWin == 2){
            DisplayXOGame(numberXO);
            printf("Computer * Win!!");
            isComplete = false;
        }else{
            
        }
    }
}
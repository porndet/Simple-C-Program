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
#define lengthColumnRow 4

/*
numberXO[0][0] = 1;
numberXO[0][1] = 2;
numberXO[0][2] = 3;
numberXO[0][3] = 4;
*/

/*
numberXO[1][0] = 5;
numberXO[1][1] = 6;
numberXO[1][2] = 7;
numberXO[1][3] = 8;
*/

/*
numberXO[2][0] = 9;
numberXO[2][1] = 10;
numberXO[2][2] = 11;
numberXO[2][3] = 12;
*/

/*
numberXO[3][0] = 13;
numberXO[3][1] = 14;
numberXO[3][2] = 15;
numberXO[3][3] = 16;
*/

int CheckWin1(char numberXO[][lengthColumnRow], char mark){

    if(numberXO[0][0] == numberXO[0][1] && numberXO[0][1] == numberXO[0][2] && numberXO[0][2] == numberXO[0][3]){
        //1 2 3 4
        if(numberXO[0][0] == mark){
            return 1;
        }else if(numberXO[0][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[1][0] == numberXO[1][1] && numberXO[1][1] == numberXO[1][2] && numberXO[1][2] == numberXO[1][3]){
        //5 6 7 8
        if(numberXO[1][0] == mark){
            return 1;
        }else if(numberXO[1][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[2][0] == numberXO[2][1] && numberXO[2][1] == numberXO[2][2] && numberXO[2][2] == numberXO[2][2]){
        //9 10 11 12
        if(numberXO[2][0] == mark){
            return 1;
        }else if(numberXO[2][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[3][0] == numberXO[3][1] && numberXO[3][1] == numberXO[3][2] && numberXO[3][2] == numberXO[3][2]){
        //13 14 15 16
        if(numberXO[3][0] == mark){
            return 1;
        }else if(numberXO[3][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][0] == numberXO[1][1] && numberXO[1][1] == numberXO[2][2] && numberXO[2][2] == numberXO[3][3]){
        //1 6 11 16
        if(numberXO[0][0] == mark){
            return 1;
        }else if(numberXO[0][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][0] == numberXO[1][0] && numberXO[1][0] == numberXO[2][0] && numberXO[2][0] == numberXO[3][0]){
        //1 5 9 13
        if(numberXO[0][0] == mark){
            return 1;
        }else if(numberXO[0][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][1] == numberXO[1][1] && numberXO[1][1] == numberXO[2][1] && numberXO[2][1] == numberXO[3][1]){
        //2 6 10 14
        if(numberXO[0][1] == mark){
            return 1;
        }else if(numberXO[0][1] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][2] == numberXO[1][2] && numberXO[1][2] == numberXO[2][2] && numberXO[2][2] == numberXO[3][2]){
        //3 7 11 15
        if(numberXO[0][2] == mark){
            return 1;
        }else if(numberXO[0][2] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][3] == numberXO[1][2] && numberXO[1][2] == numberXO[2][1] && numberXO[2][1] == numberXO[3][0]){
        //4 7 10 13
        if(numberXO[0][3] == mark){
            return 1;
        }else if(numberXO[0][3] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][3] == numberXO[1][3] && numberXO[1][3] == numberXO[2][3] && numberXO[2][3] == numberXO[3][3]){
        //4 8 12 16
        if(numberXO[0][3] == mark){
            return 1;
        }else if(numberXO[0][3] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else{
        return 0;
    }

}

int CheckWin2(char numberXO[][lengthColumnRow], char mark, char mark1){
    if(numberXO[0][0] == numberXO[0][1] && numberXO[0][1] == numberXO[0][2]){
        //1 2 3
        if(numberXO[0][0] == mark){
            return 1;
        }else if(numberXO[0][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[1][0] == numberXO[1][1] && numberXO[1][1] == numberXO[1][2]){
        //4 5 6
        if(numberXO[1][0] == mark){
            return 1;
        }else if(numberXO[1][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[2][0] == numberXO[2][1] && numberXO[2][1] == numberXO[2][2]){
        //7 8 9
        if(numberXO[2][0] == mark){
            return 1;
        }else if(numberXO[2][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][0] == numberXO[1][1] && numberXO[1][1] == numberXO[2][2]){
        //1 5 9
        if(numberXO[0][0] == mark){
            return 1;
        }else if(numberXO[0][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][0] == numberXO[1][0] && numberXO[1][0] == numberXO[2][0]){
        //1 4 7
        if(numberXO[0][0] == mark){
            return 1;
        }else if(numberXO[0][0] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][1] == numberXO[1][1] && numberXO[1][1] == numberXO[2][1]){
        //2 5 8
        if(numberXO[0][1] == mark){
            return 1;
        }else if(numberXO[0][1] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][2] == numberXO[1][1] && numberXO[1][1] == numberXO[2][0]){
        //3 5 7
        if(numberXO[0][2] == mark){
            return 1;
        }else if(numberXO[0][2] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else if(numberXO[0][2] == numberXO[1][2] && numberXO[1][2] == numberXO[2][2]){
        //3 6 9
        if(numberXO[0][2] == mark){
            return 1;
        }else if(numberXO[0][2] != '?'){
            return 2;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}


void New_DisplayXOGame(char numberXO[][lengthColumnRow], int column[], int row[]){
    printf(" ");
    for(int i = 0; i < lengthColumnRow; i++){
        printf("|%d", column[i]);
    }
    printf("|\n");
    
    printf(" ");
    for(int i = 0; i < lengthColumnRow; i++){
        printf("+-");
    }
    printf("+\n");

    for(int i = 0; i < lengthColumnRow; i++){
        printf("%d|", row[i]);
        for(int j = 0; j < lengthColumnRow; j++){
            printf("%c|", numberXO[i][j]);
        }
        printf("\n ");
        for(int i = 0; i < lengthColumnRow; i++){
            printf("+-");
        }
        printf("+\n");
    }
}

void New_Computer(char numberXO[][lengthColumnRow], char mark){
    bool isComputer = true;
    int vertical, horizontal;

    while(isComputer){
        vertical = rand() % lengthColumnRow + 1;
        horizontal = rand() % lengthColumnRow + 1;
        if(numberXO[horizontal - 1][vertical - 1] != mark && numberXO[horizontal - 1][vertical - 1] != '*'){
            isComputer = false;
            numberXO[horizontal - 1][vertical - 1] = '*';
        }
    }
    printf("Computer : * select vertical : %d\n", vertical);
    printf("Computer : * select horizontal : %d\n", horizontal);
}


void NewPlayer(char numberXO[][lengthColumnRow], char mark, String name){
    bool isPlayer = true;
    int vertical, horizontal;

    while(isPlayer){
        printf("%s : %c select vertical : ", name, mark);
        scanf("%d", &vertical);
        printf("%s : %c select horizontal : ", name, mark);
        scanf("%d", &horizontal);

        if(numberXO[horizontal - 1][vertical - 1] != mark && numberXO[horizontal - 1][vertical - 1] != '*'){
            numberXO[horizontal - 1][vertical - 1] = mark;
            isPlayer = false;
        }
    }    
}

const int CheckwinDisplayBoardGame2(char numberXO[][lengthColumnRow], String name, char mark){
    int checkWin = CheckWin1(numberXO, mark);
    if(checkWin == 1){
        // DisplayXOGame(numberXO);
        printf("%s %c Win!!\n", name, mark);
    }else if(checkWin == 2){
        // DisplayXOGame(numberXO);
        printf("Computer * Win!!\n");
    }
    return checkWin;
}

const int CheckwinDisplayBoardGame3(char numberXO[][lengthColumnRow], String name, String name1, char mark, char mark1){
    int checkWin = CheckWin1(numberXO, mark);
    if(checkWin == 1){
        // DisplayXOGame(numberXO);
        printf("%s %c Win!!\n", name, mark);
    }else if(checkWin == 2){
        // DisplayXOGame(numberXO);
        printf("%s %c Win!!\n", name1, mark1);
    }
    return checkWin;
}

int main(void){
    char numberXO1[lengthColumnRow][lengthColumnRow];
    int column[lengthColumnRow], row[lengthColumnRow];

    int checkMark, attackFirstSecond, duel, vertical, horizontal;
    bool isComplete = true;
    char Playername[10], mark;
    String nameplayer;
    srand(time(NULL));

    for(int i = 0; i < lengthColumnRow; i++){
        for(int j = 0; j < lengthColumnRow; j++){
            numberXO1[i][j] = '?';
        }
    }

    for(int i = 1, j = 0; i <= 4; i++, j++){
        column[j] = i;
    }

    for(int i = 1, j = 0; i <= 4; i++, j++){
        row[j] = i;
    }

    New_DisplayXOGame(numberXO1, column, row);

    
    printf("Duel Computer or Duel player\n");
    printf("Want duel co0mputer select 0 but select 1 will duel player\n");
    scanf("%d", &duel);

    if(duel == 0){
        printf("Duel Computer\n");

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

        printf("------ First Attack Put : (0)  Second Attack Put : (1) ------\n");
        scanf("%d", &attackFirstSecond);
        if(attackFirstSecond == 0 && attackFirstSecond == 1){
            printf("Error You put without to setting\n");
        }

        printf("------ Mark of %s is %c %s ------\n", nameplayer, mark, (attackFirstSecond == 0)? "First Attack" : (attackFirstSecond == 1)? "Second Attack" : "First Attack");

        printf("### XO GAME ###\n");
        printf("+-+-+-+\n");
        New_DisplayXOGame(numberXO1, column, row);

        while(isComplete){
            int temp = 0;
            if(attackFirstSecond == 1){
                New_Computer(numberXO1, mark);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame2(numberXO1, nameplayer, mark);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }

                NewPlayer(numberXO1, mark, nameplayer);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame2(numberXO1, nameplayer, mark);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }else{
                NewPlayer(numberXO1, mark, nameplayer);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame2(numberXO1, nameplayer, mark);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
                
                New_Computer(numberXO1, mark);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame2(numberXO1, nameplayer, mark);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }
        }
    }else{
        
        printf("Duel Player\n");
        String nameplayer1;
        char Playername1[10];
        char mark1;

        do{
            printf("------Please put name player No.1 ------\n>");
            scanf("%10s%*[^\n]", Playername);
            printf("------Player name : %s ------\n\n", Playername);
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

        printf("------ First Attack Put : (0)  Second Attack Put : (1) ------\n");
        scanf("%d", &attackFirstSecond);
        if(attackFirstSecond == 0 && attackFirstSecond == 1){
            printf("Error You put without to setting\n");
        }

        printf("------ Mark of %s is %c %s ------\n", nameplayer, mark, (attackFirstSecond == 0)? "First Attack" : (attackFirstSecond == 1)? "Second Attack" : "First Attack");

        do{
            printf("\n------Please put name player No.2 ------\n>");
            scanf("%10s%*[^\n]", Playername1);
            printf("------Player name : %s ------\n\n", Playername1);
            strcpy(nameplayer1, Playername1);
        }while(strncmp(Playername1, "Computer", strlen("Computer")) == 0); 

        printf("------Please put player mark------\n");
        printf("Mark to used #, $, %, &, @, A-Z , a-z\n");
        scanf("%s", &mark1);

        checkMark = (int)mark1;

        if(!((checkMark >= 35 && checkMark <= 38) || checkMark == 64 || (checkMark >= 65 && checkMark <= 90) || (checkMark >= 97 && checkMark <= 122))){
            printf("Error You put mark without to setting\n");
            mark1 = '*';        
        } 
        printf("------ Mark of %s is %c ------\n", nameplayer1, mark1);     


        printf("### XO GAME ###\n");
        printf("+-+-+-+\n");
        New_DisplayXOGame(numberXO1, column, row);

        while(isComplete){     
            int temp = 0;
            if(attackFirstSecond == 1){
                NewPlayer(numberXO1, mark1, nameplayer1);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame3(numberXO1, nameplayer, nameplayer1, mark, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }

                NewPlayer(numberXO1, mark, nameplayer);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame3(numberXO1, nameplayer, nameplayer1, mark, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }else{
                NewPlayer(numberXO1, mark, nameplayer);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame3(numberXO1, nameplayer, nameplayer1, mark, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }

                NewPlayer(numberXO1, mark1, nameplayer1);
                New_DisplayXOGame(numberXO1, column, row);
                temp = CheckwinDisplayBoardGame3(numberXO1, nameplayer, nameplayer1, mark, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }

        }
        
    }
    
}
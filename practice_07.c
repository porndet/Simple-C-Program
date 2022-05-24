#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];
#define lengthColumnRow 4

void New_DisplayXOGame(char* numberXO, int* column, int* row, int ver, int hori){
    printf(" ");
    for(int i = 0; i < ver; i++){
        printf("|%d", column[i]);
    }
    printf("|\n");

    printf(" ");
    for(int i = 0; i < ver; i++){
        printf("+-");
    }
    printf("+\n");

    for(int i = 0; i < hori; i++){
        printf("%d|", row[i]);
        for(int j = 0; j < ver; j++){
            printf("%c|", *(numberXO + i * ver + j));
        }
        printf("\n");
        for(int i = 0; i < ver; i++){
            printf("+-");
        }
        printf("+\n");
    }
}

void New_Computer(char* numberXO, char mark, int ver, int hori){
    bool isComputer = true;
    int vertical, horizontal;

    while(isComputer){
        vertical = rand() % ver + 1;
        horizontal = rand() % hori + 1;
        if(*(numberXO + (horizontal - 1) * ver + (vertical - 1)) != mark && *(numberXO + (horizontal - 1) * ver + (vertical - 1)) != '*'){
            *(numberXO + (horizontal - 1) * ver + (vertical - 1)) = '*';
            isComputer = false;
        }
    }
    printf("Computer : * select vertical : %d\n", vertical);
    printf("Computer : * select horizontal : %d\n", horizontal);
}

void NewPlayer(char* numberXO, char mark, String name, int ver){
    bool isPlayer = true;
    int vertical, horizontal;

    while(isPlayer){
        printf("%s : %c select vertical : ", name, mark);
        scanf("%d", &vertical);
        printf("%s : %c select horizontal : ", name, mark);
        scanf("%d", &horizontal); 
        *(numberXO + (horizontal - 1) * ver + (vertical - 1)) = mark;
        isPlayer = false;     
    }
}

const int CheckrowXOGame(char* numberXO, char mark, char mark1, int ver, int hori){
    int row = 0, rowcom = 0;
    bool isTrue = false;

    for(int i = 0; i < hori; i++){
        for(int j = 0; j < ver; j++){
            if(*(numberXO + i * ver + j) == mark){
                row += 1;
            }else if(*(numberXO + i * ver + j) == mark1){
                rowcom += 1;
            }
            if(row == ver || rowcom == ver){
                isTrue = true;
                break;
            }
        }
        if(!isTrue){
            row = 0;
            rowcom = 0;
        }
        else{
            if(row == ver){
                return 1;
            }else{
                return 2;
            }
            break;
        }
    }
    if(!isTrue)
        return 0;   
}

const int CheckcolumnXOGame(char* numberXO, char mark, char mark1, int ver, int hori){
    int column = 0;
    int stackColumn[9] = {0};
    int stackColumnCom[9] = {0};
    bool isTrue = false, isTrueCom = false;

    for(int i = 0; i < hori; i++){
        for(int j = 0; j < ver; j++){
            if(*(numberXO + i * ver + j) == mark){
                if(j == 0)
                    stackColumn[j] += 1;
                else if(j == 1)
                    stackColumn[j] += 1;
                else if(j == 2)
                    stackColumn[j] += 1;
                else if(j == 3)
                    stackColumn[j] += 1;
                else if(j == 4)
                    stackColumn[j] += 1;
                else if(j == 5)
                    stackColumn[j] += 1;
                else if(j == 6)
                    stackColumn[j] += 1; 
                else if(j == 7)
                    stackColumn[j] += 1;
                else if(j == 8)
                    stackColumn[j] += 1;
                else if(j == 9)
                    stackColumn[j] += 1;
            }            
            else if(*(numberXO + i * ver + j) == mark1){
                if(j == 0)
                    stackColumnCom[j] += 1;
                else if(j == 1)
                    stackColumnCom[j] += 1;
                else if(j == 2)
                    stackColumnCom[j] += 1;
                else if(j == 3)
                    stackColumnCom[j] += 1;
                else if(j == 4)
                    stackColumnCom[j] += 1;
                else if(j == 5)
                    stackColumnCom[j] += 1;
                else if(j == 6)
                    stackColumnCom[j] += 1; 
                else if(j == 7)
                    stackColumnCom[j] += 1;
                else if(j == 8)
                    stackColumnCom[j] += 1;
                else if(j == 9)
                    stackColumnCom[j] += 1;
            }

            if(stackColumn[j] == hori){
                isTrue = true;
                break;
            }else if(stackColumnCom[j] == hori){
                isTrueCom = true;
                break;
            }
        }
        if(isTrue){
            return 1;
            break;
        }else if(isTrueCom){
            return 2;
            break;
        }
    }

    if(!isTrue)
        return 0;
}

const int CheckobliqueXOGame(char* numberXO, char mark, char mark1, int ver, int hori){
    int oblique = 0;
    bool isTrue = false;
    
    for(int i = 0; i < hori; i++){
        for(int j = 0; j < ver; j++){
            if(*(numberXO + i * ver + j) == mark){
                if(i == j){
                    oblique += 1;
                }

                if(oblique == hori){
                    isTrue = true;
                    break;
                }
            }
        }
    }
    return 0;
}

const int CheckwinXOGame(char* numberXO, String name, char mark, int ver, int hori, char mark1){
    
    int Checkrow = CheckrowXOGame(numberXO, mark, mark1, ver, hori);
    int Checkcolumn = CheckcolumnXOGame(numberXO, mark, mark1, ver, hori);
    CheckobliqueXOGame(numberXO, mark, mark1, ver, hori);
    
    if(Checkrow != 0){
        if(Checkrow == 1){
            return 1;
        }else{
            return 2;
        }
    }else{
        if(Checkcolumn != 0){
            if(Checkcolumn == 1){
                return 1;
            }else{
                return 2;
            }
        }else{
            return 0;
        }
    }
    
    // int count = 0, countcom = 0;
    // int countrow = ver;
    // int countcolumn = hori;
    // int column[10] = {0};
    // int row[10] = {0};
    // int rowcom[10] = {0};
    // int columncom[10] = {0};
    // int stack[9] = {0};
    // int top = 0;

    // for(int i = 0; i < 9; i++){
    //     printf("%d ", stack[i]);
    // }
    // printf("\n");
    
    // printf("%d", CheckrowXOGame(numberXO, mark, mark1, ver, hori));

    /*
    for(int i = 0; i < hori; i++){
        for(int j = 0; j < ver; j++){
            if(i == 0){
                if(*(numberXO + i * ver + j) == mark){
                    row[0] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[0] += 1;
                }
                if(countrow == row[0]){
                    return 1;
                    break;
                }else if(countrow == rowcom[0]){
                    return 2;
                    break;
                }      
            }else if(i == 1){
                if(*(numberXO + i * ver + j) == mark){
                    row[1] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[1] += 1;
                }
                if(countrow == row[1]){
                    return 1;
                    break;
                }else if(countrow == rowcom[1]){
                    return 2;
                    break;
                }              
            }else if(i == 2){
                if(*(numberXO + i * ver + j) == mark){
                    row[2] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[2] += 1;
                }
                if(countrow == row[2]){
                    return 1;
                    break;
                }else if(countrow == rowcom[2]){
                    return 2;
                    break;
                }             
            }else if(i == 3){
                if(*(numberXO + i * ver + j) == mark){
                    row[3] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[3] += 1;
                }
                if(countrow == row[3]){
                    return 1;
                    break;
                }else if(countrow == rowcom[3]){
                    return 2;
                    break;
                }              
            }else if(i == 4){
                if(*(numberXO + i * ver + j) == mark){
                    row[4] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[4] += 1;
                }
                if(countrow == row[4]){
                    return 1;
                    break;
                }else if(countrow == rowcom[4]){
                    return 2;
                    break;
                }             
            }else if(i == 5){
                if(*(numberXO + i * ver + j) == mark){
                    row[5] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[5] += 1;
                }
                if(countrow == row[5]){
                    return 1;
                    break;
                }else if(countrow == rowcom[5]){
                    return 2;
                    break;
                }             
            }else if(i == 6){
                if(*(numberXO + i * ver + j) == mark){
                    row[6] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[6] += 1;
                }
                if(countrow == row[6]){
                    return 1;
                    break;
                }else if(countrow == rowcom[6]){
                    return 2;
                    break;
                }            
            }else if(i == 7){
                if(*(numberXO + i * ver + j) == mark){
                    row[7] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[7] += 1;
                }
                if(countrow == row[7]){
                    return 1;
                    break;
                }else if(countrow == rowcom[7]){
                    return 2;
                    break;
                }             
            }else if(i == 8){
                if(*(numberXO + i * ver + j) == mark){
                    row[8] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[8] += 1;
                }
                if(countrow == row[8]){
                    return 1;
                    break;
                }else if(countrow == rowcom[8]){
                    return 2;
                    break;
                }             
            }else if(i == 9){
                if(*(numberXO + i * ver + j) == mark){
                    row[9] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    rowcom[9] += 1;
                }
                if(countrow == row[9]){
                    return 1;
                    break;
                }else if(countrow == rowcom[9]){
                    return 2;
                    break;
                }             
            }                   

            if(j == 0){
                if(*(numberXO + i * ver + j) == mark){
                    column[0] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[0] += 1;
                }
                if(countcolumn == column[0]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[0]){
                    return 2;
                    break;
                }
            }else if(j == 1){
                if(*(numberXO + i * ver + j) == mark){
                    column[1] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[1] += 1;
                }
                if(countcolumn == column[1]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[1]){
                    return 2;
                    break;
                }           
            }else if(j == 2){
                if(*(numberXO + i * ver + j) == mark){
                    column[2] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[2] += 1;
                }
                if(countcolumn == column[2]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[2]){
                    return 2;
                    break;
                }              
            }else if(j == 3){
                if(*(numberXO + i * ver + j) == mark){
                    column[3] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[3] += 1;
                }
                if(countcolumn == column[3]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[3]){
                    return 2;
                    break;
                }                              
            }else if(j == 4){
                if(*(numberXO + i * ver + j) == mark){
                    column[4] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[4] += 1;
                }
                if(countcolumn == column[4]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[4]){
                    return 2;
                    break;
                }                               
            }else if(j == 5){
                if(*(numberXO + i * ver + j) == mark){
                    column[5] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[5] += 1;
                }
                if(countcolumn == column[5]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[5]){
                    return 2;
                    break;
                }                              
            }else if(j == 6){
                if(*(numberXO + i * ver + j) == mark){
                    column[6] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[6] += 1;
                }
                if(countcolumn == column[6]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[6]){
                    return 2;
                    break;
                }                                 
            }else if(j == 7){
                if(*(numberXO + i * ver + j) == mark){
                    column[7] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[7] += 1;
                }
                if(countcolumn == column[7]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[7]){
                    return 2;
                    break;
                }                              
            }else if(j == 8){
                if(*(numberXO + i * ver + j) == mark){
                    column[8] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[8] += 1;
                }
                if(countcolumn == column[8]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[8]){
                    return 2;
                    break;
                }                                 
            }else if(j == 9){
                if(*(numberXO + i * ver + j) == mark){
                    column[9] += 1;
                }else if(*(numberXO + i * ver + j) == mark1){
                    columncom[9] += 1;
                }
                if(countcolumn == column[9]){
                    return 1;
                    break;
                }else if(countcolumn == columncom[9]){
                    return 2;
                    break;
                }                                
            }
        }
    }
    */

    // for(int i = 0; i < 10; i++){
    //     printf("row[%d] : %d ", i, row[i]);
    // }
    // printf("\n");

    // for(int i = 0; i < 10; i++){
    //     printf("column[%d] : %d ", i, column[i]);
    // }
    // printf("\n");
    
}

int main(void){
    int checkMark, attackFirstSecond, duel, vertical, horizontal;
    bool isComplete = true;
    char Playername[10], mark;
    String nameplayer;
    srand(time(NULL));

    printf("3~9 You want vertical : ");
    scanf("%d", &vertical);
    printf("3~9 You want horizontal : ");
    scanf("%d", &horizontal);
    
    char *ptrNumberXO = malloc((horizontal * vertical) * sizeof(char));
    int *ptrcolumn = malloc(vertical * sizeof(int));
    int *ptrrow = malloc(horizontal * sizeof(int));

    int i, j;
    for (i = 0; i < horizontal; i++)
        for (j = 0; j < vertical; j++)
            *(ptrNumberXO + i * vertical + j) = '?';    

    for(int i = 0; i < vertical; i++){
        ptrcolumn[i] = i + 1;
    }

    for(int i = 0; i < horizontal; i++){
        ptrrow[i] = i + 1;
    }

    // New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);

    printf("Duel Computer or Duel player\n");
    printf("Want duel computer select 0 but select 1 will duel player\n");
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
        New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);

        while(isComplete){
            int temp = 0;
            if(attackFirstSecond == 1){
                New_Computer(ptrNumberXO, mark, vertical, horizontal);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, '*');
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }

                NewPlayer(ptrNumberXO, mark, nameplayer, vertical);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, '*');
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }else{
                NewPlayer(ptrNumberXO, mark, nameplayer, vertical);
                New_Computer(ptrNumberXO, mark, vertical, horizontal);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, '*');
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
        New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);

        while(isComplete){     
            int temp = 0;
            if(attackFirstSecond == 1){
                NewPlayer(ptrNumberXO, mark, nameplayer, vertical);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }

                NewPlayer(ptrNumberXO, mark1, nameplayer1, vertical);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }else{
                NewPlayer(ptrNumberXO, mark1, nameplayer1, vertical);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }

                NewPlayer(ptrNumberXO, mark, nameplayer, vertical);
                New_DisplayXOGame(ptrNumberXO, ptrcolumn, ptrrow, vertical, horizontal);
                temp = CheckwinXOGame(ptrNumberXO, nameplayer, mark, vertical, horizontal, mark1);
                if(temp == 1 || temp == 2){
                    isComplete = false;
                    break;
                }
            }

        }
    }
    
}
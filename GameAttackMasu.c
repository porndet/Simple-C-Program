#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isTrue = true;

int main() {
    int user;
    int numberinList = 1;
    while(isTrue){
        srand(time(NULL));
        int computerrandom = rand() % 9 + 1;
        
        printf("Tataku masu (1-9) wo erandekudasai\n");
        printf("+-----+\n");
        for(int i = 0; i <= 2; i++){
            printf("|%d|%d|%d|\n", numberinList, numberinList + 1, numberinList + 2);
            if(i != 2){ printf("|-----|\n");}
            numberinList += 3;
        }
        printf("+-----+\n>");
        scanf("%d", &user);

        if(user == computerrandom){
            printf("HIT!!\n\n");
            return 0;
        }else{
            printf("MISS!!\n\n");
            numberinList = 1;
        }
    }
}
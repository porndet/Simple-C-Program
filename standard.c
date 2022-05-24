#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

typedef struct Reserveseat
{
    String Seat;
    FILE* filereserve;
    int length, Completereserve;
    bool isTrue;
} Reserveseat;


int main(void){
    Reserveseat Reserve;
    Reserve.length = 5;
    Reserve.isTrue = true;
    Reserve.Completereserve = 0;

    char StackChar[50][100] = {"B8", "A10", "C10", "A4", "E5"};
    char seat1[5];
    
    while(Reserve.isTrue){
        int tempseat = 0;
        printf("No.Seat (A~E, 1~10)\n>");
        scanf("%s", &seat1);
        tempseat = (int)seat1[1] + (int)seat1[2];

        if((seat1[0] >= 65 && seat1[0] <= 69) && (tempseat == 97 || tempseat >= 49 && tempseat <= 57) ){
            strcpy(Reserve.Seat, seat1);
            for(int i = 0; i < Reserve.length; i++){
                if(strcmp(Reserve.Seat, StackChar[i]) == 0){
                    printf("You Seat Reserve!!\n");
                    break;
                }
                Reserve.Completereserve++;
            }

            if(Reserve.Completereserve == Reserve.length){
                strcpy(StackChar[Reserve.length], Reserve.Seat);
                Reserve.length++;
                printf("You can seat reserve!!\n");
                Reserve.isTrue = false;
                break;
            }
        }else{
            printf("Put english charecter or number seat wrong\n\n");
        }
    }
}
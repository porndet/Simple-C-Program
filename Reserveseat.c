#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];
#define SeatNumber 5

typedef struct Reserveseat
{
    String Seat;
    FILE* filereserve;
    int length, Completereserve;
    bool isTrue;
    char TempString[10];
    int TempSeatInt;
} Reserveseat;

typedef struct Showseat{
    int SeatCount;
    int SeatAny[10];
    char SeatEnglish;
} Showseat;

typedef struct ReadfileReserveSeat{
    char Seat[20];
} ReadfileReserveSeat;

void DisplaySeat(Showseat Seat, Reserveseat Reserve){
    printf("%c ", Seat.SeatEnglish);
    for(int j = 0; j < 10; j++){
        printf("%d ", Seat.SeatAny[j]);
        fprintf(Reserve.filereserve,"%d", Seat.SeatAny[j]);
    }
    fprintf(Reserve.filereserve, "\n");
    printf("\n");
}

int main(void){
    Reserveseat Reserve;
    ReadfileReserveSeat Rb[5];
    Reserve.length = 0;
    Reserve.isTrue = true;
    Reserve.Completereserve = 0;
    char ch;

    char StackChar[50][100] = {0};
    char seat1[5], moji[20];

    Reserve.filereserve = fopen("File_Reserveseat.txt", "rb");
    for (int i = 0; fgets(moji, 15, Reserve.filereserve) != NULL; i++)
	{
        strcpy(Rb[i].Seat, moji);
	}
    fclose(Reserve.filereserve);

    for(int i = 0; i < 10; i++){
        if(Rb[0].Seat[i] == '1'){
            char temp[4][10] = {0};
            temp[0][0] = 'A';
            if(i == 9){
                temp[0][1] = (1) + '0';
                temp[0][2] = (0) + '0';
            }else{
                temp[0][1] = (i + 1) + '0';
            }
            strcpy(StackChar[Reserve.length], temp[0]);
            Reserve.length++;
        }
    }

    for(int i = 0; i < 10; i++){
        if(Rb[1].Seat[i] == '1'){
            char temp[4][10] = {0};
            temp[0][0] = 'B';
            if(i == 9){
                temp[0][1] = (1) + '0';
                temp[0][2] = (0) + '0';
            }else{
                temp[0][1] = (i + 1) + '0';
            }
            strcpy(StackChar[Reserve.length], temp[0]);
            Reserve.length++;
        }
    }

    for(int i = 0; i < 10; i++){
        if(Rb[2].Seat[i] == '1'){
            char temp[4][10] = {0};
            temp[0][0] = 'C';
            if(i == 9){
                temp[0][1] = (1) + '0';
                temp[0][2] = (0) + '0';
            }else{
                temp[0][1] = (i + 1) + '0';
            }
            strcpy(StackChar[Reserve.length], temp[0]);
            Reserve.length++;
        }
    }

    for(int i = 0; i < 10; i++){
        if(Rb[3].Seat[i] == '1'){
            char temp[4][10] = {0};
            temp[0][0] = 'D';
            if(i == 9){
                temp[0][1] = (1) + '0';
                temp[0][2] = (0) + '0';
            }else{
                temp[0][1] = (i + 1) + '0';
            }
            strcpy(StackChar[Reserve.length], temp[0]);
            Reserve.length++;
        }
    }

    for(int i = 0; i < 10; i++){
        if(Rb[4].Seat[i] == '1'){
            char temp[4][10] = {0};
            temp[0][0] = 'E';
            if(i == 9){
                temp[0][1] = (1) + '0';
                temp[0][2] = (0) + '0';
            }else{
                temp[0][1] = (i + 1) + '0';
            }
            strcpy(StackChar[Reserve.length], temp[0]);
            Reserve.length++;
        }
    }

    // for(int i = 0; i < Reserve.length; i++){
    //     printf("%d - %s\n",i, StackChar[i]);
    // }

    // Reserve.filereserve = fopen("File_Reserveseat.txt", "w+");

    while(Reserve.isTrue){
        Reserve.TempSeatInt = 0;
        printf("No.Seat (A~E, 1~10)\n>");
        scanf("%s", &seat1);
        Reserve.TempSeatInt = (int)seat1[1] + (int)seat1[2];

        if((seat1[0] >= 65 && seat1[0] <= 69) && (Reserve.TempSeatInt == 97 || Reserve.TempSeatInt >= 49 && Reserve.TempSeatInt <= 57) ){
            strcpy(Reserve.Seat, seat1);
            for(int i = 0; i < Reserve.length; i++){
                if(strcmp(Reserve.Seat, StackChar[i]) == 0){
                    printf("You Seat Reserve!!\n");
                    Reserve.Completereserve = 0;
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

    Showseat A = {0}, B = {0}, C = {0}, D = {0}, E = {0};
    A.SeatEnglish = 'A';
    B.SeatEnglish = 'B';
    C.SeatEnglish = 'C';
    D.SeatEnglish = 'D';
    E.SeatEnglish = 'E';

    printf("  1 2 3 4 5 6 7 8 9 10\n");
    for(int i = 0; i < Reserve.length; i++){
        Reserve.TempSeatInt = 0;
        memcpy(Reserve.TempString, StackChar[i], 3);
        Reserve.TempSeatInt = ((int)Reserve.TempString[1] + (int)Reserve.TempString[2]) - 48;
        if(Reserve.TempSeatInt == 49)
            Reserve.TempSeatInt = 10;
        
        if(Reserve.TempString[0] == 'A'){
            A.SeatCount += 1;
            A.SeatAny[Reserve.TempSeatInt - 1] = 1;
        }else if(Reserve.TempString[0] == 'B'){
            B.SeatCount += 1;
            B.SeatAny[Reserve.TempSeatInt - 1] = 1;
        }else if(Reserve.TempString[0] == 'C'){
            C.SeatCount += 1;
            C.SeatAny[Reserve.TempSeatInt - 1] = 1;
        }else if(Reserve.TempString[0] == 'D'){
            D.SeatCount += 1;
            D.SeatAny[Reserve.TempSeatInt - 1] = 1;
        }else if(Reserve.TempString[0] == 'E'){
            E.SeatCount += 1;
            E.SeatAny[Reserve.TempSeatInt - 1] = 1;
        }
    }

    Reserve.filereserve = fopen("File_Reserveseat.txt", "w+");

    for(int i = 0; i < SeatNumber; i++){
        if(i == 0){
            DisplaySeat(A, Reserve);
        }
        else if(i == 1){
            DisplaySeat(B, Reserve);
        }
        else if(i == 2){
            DisplaySeat(C, Reserve);
        }
        else if(i == 3){
            DisplaySeat(D, Reserve);
        }        
        else if(i == 4){
            DisplaySeat(E, Reserve);
        }
    }

    fclose(Reserve.filereserve);
    
}
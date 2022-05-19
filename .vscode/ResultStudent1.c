#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

typedef struct ResultStudent
{
    char name[100];
    int point;
    char valuation;
} R1, *R2;

int main(void){
    R1 var;
    R2 var1;

    strcpy(var.name, "Porndet Pipituntonsan");
    var.point = 89;
        
    if(var.point  >= 90){
        var.valuation = 'A';
    }else if(var.point  >= 75 || var.point  <= 89){
        var.valuation = 'B';
    }else if(var.point >= 60 || var.point  <= 74){
        var.valuation = 'C';
    }else{
        var.valuation = 'D';
    }
    
    var1 = &var;
    printf("Name : %s\n", var1->name);
    printf("Point : %d\n", var1->point);
    printf("%s Valuation : %c", var1->name, var1->valuation);


    // struct ResultStudent P2;
    // strcpy(P2.name, "Porndet Pipituntonsan");
    // P2.point = 89;

    // if(P2.point  >= 90){
    //     P2.valuation = 'A';
    // }else if(P2.point  >= 75 || P2.point  <= 89){
    //     P2.valuation = 'B';
    // }else if(P2.point >= 60 || P2.point  <= 74){
    //     P2.valuation = 'C';
    // }else{
    //     P2.valuation = 'D';
    // }

    // struct ResultStudent *P1 = &P2;
    // printf("Name : %s\n", P1->name);
    // printf("Point : %d\n", P1->point);
    // printf("Valuation : %c", P1->valuation);

    return 0;
}
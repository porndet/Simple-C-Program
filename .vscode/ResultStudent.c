#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

struct ResultStudent
{
    char name[100];
    int point;
    char valuation;
};

int main(void){
    struct ResultStudent P2;
    strcpy(P2.name, "Porndet Pipituntonsan");
    P2.point = 89;

    if(P2.point  >= 90){
        P2.valuation = 'A';
    }else if(P2.point  >= 75 || P2.point  <= 89){
        P2.valuation = 'B';
    }else if(P2.point >= 60 || P2.point  <= 74){
        P2.valuation = 'C';
    }else{
        P2.valuation = 'D';
    }

    struct ResultStudent *P1 = &P2;
    printf("Name : %s\n", P1->name);
    printf("Point : %d\n", P1->point);
    printf("Valuation : %c", P1->valuation);

    return 0;
}
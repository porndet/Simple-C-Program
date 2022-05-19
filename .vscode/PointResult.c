#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

#define lengthArr 5

typedef struct PointResult
{
    int stnum;
    int japanese;
    int calculate;
    int cook;
    int society;
    int res;
} P1[5], P2, P3[5];

int main(void){
    P1 Point = {
        {1001, 85, 74, 63, 90, 0},
        {1002, 78, 65, 70, 62, 0},
        {1003, 89, 92, 88, 76, 0}, 
        {1004, 32, 48, 66, 25, 0}, 
        {1005, 92, 76, 81, 98, 0}
    };

    P3 *PointerTemp = &Point;

    for(int i = 0; i < lengthArr; i++){
        (*PointerTemp)[i].res = (*PointerTemp)[i].japanese +
                                (*PointerTemp)[i].cook +
                                (*PointerTemp)[i].society + 
                                (*PointerTemp)[i].calculate;
    }

    P2 Temppoint = { 0 };

    for(int i = 0; i < lengthArr; i++){
        for(int j = i + 1; j < lengthArr; j++){
            if((*PointerTemp)[j].res > (*PointerTemp)[i].res){
                Temppoint = (*PointerTemp)[i];
                (*PointerTemp)[i] = (*PointerTemp)[j];
                (*PointerTemp)[j] = Temppoint;
            }
            // printf("%d - %d\n", (*PointerTemp)[i].res, (*PointerTemp)[j].res);
        }
        // printf("\n");
    }

    for(int i = 0; i < lengthArr; i++){
        printf("%d   %d   %d   %d   %d   %d\n",
            (*PointerTemp)[i].stnum, 
            (*PointerTemp)[i].japanese, 
            (*PointerTemp)[i].calculate, 
            (*PointerTemp)[i].cook, 
            (*PointerTemp)[i].society, 
            (*PointerTemp)[i].res
        );
    }

    /*
    for(int i = 0; i < lengthArr; i++){
        Point[i].res = Point[i].japanese + Point[i].cook + Point[i].society + Point[i].calculate;
    }

    P2 Temppoint = { 0 };

    for(int i = 0; i < lengthArr; i++){
        for(int j = i + 1; j < lengthArr; j++){
            if(Point[j].res > Point[i].res){
                Temppoint = Point[i];
                Point[i] = Point[j];
                Point[j] = Temppoint;
            }
            // printf("%d - %d\n", Point[i].stnum, Point[j].stnum);
        }
    }

    for(int i = 0; i < lengthArr; i++){
        printf("%d   %d   %d   %d   %d   %d   %d\n", Point[i].stnum, Point[i].japanese, Point[i].calculate, Point[i].cook, Point[i].stnum, Point[i].society, Point[i].res);
    }
    */
    return 0;
}
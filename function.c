#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef char String[1024];

// int mathMax(int x, int y){
//     return (x > y)? x : y;
// }

int iscanf(){
    String value;
    scanf("%s", value);
    return atoi(value);
}

int mathMaxCheck(int x,  int y){
    return (x == y)? 2 : (x > y)? 1 : 3;
}

void displaymathMax(int max, int result, int result1){
    switch(max){
        case 1:
            printf("Val one Big val Two : %d", result);
        break;
        case 2:
            printf("Val one equal val Two : %d", result);
        break;
        case 3:
            printf("Val two Big val one : %d", result1);
        break;
    }
}

double calcCircleLength(double r){
    return 2 * 3.14 * r;
}

double calcCircleArea(double r){
    return 3.14 * pow(r, 2);
}

void ArraycalcCircleLengthArea(double radius, double *r, double *a){
    *r = 2 * 3.14 * radius;
    *a = 3.14 * pow(radius, 2);
}

typedef struct 
{
    int T1;
    int T2;
    double Area; 
} Triangle;

double triangleCalcArea(int x, int y){
    return 0.5 * x * y;
}

Triangle triangleCalcArea_sturct(Triangle x){
    x.T1 = iscanf();
    x.T2 = iscanf();
    x.Area = 0.5 * x.T1 * x.T2;
    return x;
}

int main(){
    // printf("Value from user radius : ");
    // int radius = iscanf();
    // printf("%.2f\n", calcCircleLength(radius));
    // printf("%.2f", calcCircleArea(radius));

    // double r, a;
    // ArraycalcCircleLengthArea(radius, &r, &a);
    // printf("\n%.2f\n%.2f", r, a);

    // printf("Value One : "); int result = iscanf();
    // printf("Value Two : "); int result1 = iscanf();
    // printf("Big Value : %d", mathMaxCheck(result,result1));
    // displaymathMax(mathMaxCheck(result, result1), result, result1);
   
    Triangle First_T = { 0 };

    // First_T.T1 = iscanf();
    // First_T.T2 = iscanf();
    // First_T.Area = triangleCalcArea(First_T.T1, First_T.T2);
    // printf("Result : %.2f", First_T.Area);

    First_T = triangleCalcArea_sturct(First_T);
    printf("Result : %.2f", First_T.Area);

    return 0;
}

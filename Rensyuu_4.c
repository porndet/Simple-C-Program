#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

void Scanf_Int(char text[100], int *totalPoint, int id){
    String stringVar;
    printf("%s - Person %d : ", text, id + 1);
    scanf("%s", stringVar);
    *totalPoint = atoi(stringVar);
}

// void DisplayResult(Classstudent c1){
//     printf("%d", c1.Total);
// }

typedef struct Classstudent
{
    int Student[3];
    int lengthSize;
    int Total;
} Classstudent;


int main(){ 
    /*
    int Classone[3], Classtwo[3];
    int lengthSizeOne = sizeof(Classone) / sizeof(int);
    int lengthSizeTwo = sizeof(Classtwo) / sizeof(int);
    int TotalClassone = 0, TotalClasstwo = 0;

    for(int i = 0; i < lengthSizeOne; i++){
        Scanf_Int("Class 1", &Classone[i], i);
        TotalClassone = TotalClassone + Classone[i];
    }

    for(int i = 0; i < lengthSizeTwo; i++){
        Scanf_Int("Class 2", &Classtwo[i], i);
        TotalClasstwo += Classtwo[i];
    }

    printf("        PointTotal  NormalPoint\n");
    printf("Class 1 :   %d        %.1f", TotalClassone, (float)TotalClassone / lengthSizeOne);
    printf("\nClass 2 :   %d        %.1f", TotalClasstwo, (float)TotalClasstwo / lengthSizeTwo);
    */

    Classstudent Classone = {0};
    Classstudent Classtwo = {0};

    Classone.lengthSize = sizeof(Classone.Student) / sizeof(int);
    Classtwo.lengthSize = sizeof(Classtwo.Student) / sizeof(int);

    for(int i = 0; i < Classone.lengthSize; i++){
        Scanf_Int("Class 1", &Classone.Student[i], i);
        Classone.Total += Classone.Student[i];
    }
    
    for(int i = 0; i < Classtwo.lengthSize; i++){
        Scanf_Int("Class 2", &Classtwo.Student[i], i);
        Classtwo.Total += Classtwo.Student[i];
    }

    printf("        PointTotal  NormalPoint\n");
    printf("Class 1 :   %d        %.1f", Classone.Total, (float)Classone.Total / Classone.lengthSize);
    printf("\nClass 2 :   %d        %.1f", Classtwo.Total, (float)Classtwo.Total / Classtwo.lengthSize);

    return 0;
}
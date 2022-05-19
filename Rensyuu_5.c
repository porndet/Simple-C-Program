#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

int RandomNum(){
    return rand() % 6 + 1;
}

int main(){ 
    int arrayTwo[6][2] = { 0 };
    srand(time(NULL));

    for(int i = 0; i < 6; i++){
        arrayTwo[i][0] = i + 1;
    }

    for(int i = 0; i < 100; i++){
        switch (RandomNum())
        {
            case 1:
                arrayTwo[0][1] += 1;
            break;

            case 2:
                arrayTwo[1][1] += 1;
            break;

            case 3:
                arrayTwo[2][1] += 1;
            break;

            case 4:
                arrayTwo[3][1] += 1;
            break;

            case 5:
                arrayTwo[4][1] += 1;
            break;

            case 6:
                arrayTwo[5][1] += 1;
            break;

            default:
            break;
        }
    }

    for(int i = 0; i < 6; i++){
        printf("%d  %d ", (i + 1), arrayTwo[i][1]);
        for(int j = 0; j < arrayTwo[i][1]; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];
bool isTrue = true;
int Round = 1;

int main() {

    srand(time(NULL));
    int Computerrandom = rand() % 100;
    printf("%d\n", Computerrandom);

    while(isTrue){
        String user;
        printf("(Round %d)\n", Round);
        printf("0 - 100 no suuji wo nyuuryokushitekudasai : ");
        scanf("%s", user);

        if(atoi(user) == Computerrandom){
            printf("Seikaidesu\n\n");
            return 0;
        }else if(atoi(user) > Computerrandom)
            printf("More value\n\n");
        else
            printf("Less value\n\n");
        Round++;
    }
    return 0;
}
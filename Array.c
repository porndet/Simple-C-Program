#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

int main() {
    // srand((unsigned)time(NULL));
    // enum { FIRE, WATER, WIND, EARTH };

    // for(int i = 0; i< 10; i++){
    //     int gemType = rand() % 4;
    //     switch (gemType)
    //     {
    //         case FIRE:
    //             printf("$ ");
    //             break;
    //         case WATER:
    //             printf("* ");
    //             break;
    //         case WIND:
    //             printf("@ ");
    //             break;
    //         case EARTH:
    //             printf("# ");
    //             break;                        
    //     }
    // }

    // printf("\n");

    // int gems[10];
    // gems[1] = 3;
    // printf("%d\n", gems[1]);

    // int i;
    // printf("Hensuu i no naiyou : %d\n", i);
    // int a[5];
    // printf("Hairetsu a Youso[0] no naiyou : %d\n", a[0]);

    srand((unsigned)time(NULL));
    enum {FIRE, WATER, WIND, EARTH};
    int gems[10];
    int length = sizeof(gems) / sizeof(int);

    for(int i = 0; i < length; i++){
        int gemType = rand() % 4;
        gems[i] = gemType;
    }

    for(int i = 0; i< length; i++){
        switch (gems[i])
        {
            case FIRE:
                printf("$ ");
                break;
            case WATER:
                printf("* ");
                break;
            case WIND:
                printf("@ ");
                break;
            case EARTH:
                printf("# ");
                break;                        
        }
    }

    // for(int i = 0; i < length; i++){
    //     printf("%d ", gems[i]);
    // }

    // typedef struct
    // {
    //     String Nekoname;
    //     int Nekoage;
    // } Neko;
    
    // Neko p1 = { "Kotarou", 5 };
    // printf("\n- - - - - - - Neko - - - - - - - - -");
    // printf("\n| Namae wa %s desu            |\n| Nenrei wa %d                      |\n", p1.Nekoname, p1.Nekoage);
    // printf("- - - - - - - - - - - - - - - - - -\n\n");

    // int scores[] = { 75, 57, 90, 46, 82};
    // int sum = 0;
    // int lengthscores = sizeof(scores) / sizeof(int);
    // for(int i = 0; i < lengthscores; i++){
    //     sum += scores[i];
    // }
    // int avg = sum / 5;
    // printf("Gougakuten : %d\n", sum);
    // printf("Heikinten : %d\n", avg);

    printf("");
    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

typedef enum {RED,  YELLOW, GREEN} Signal;

#define Working 0
#define Failed 1
#define Freezed 2

int main() {
    struct MONSTER
    {
        String name;
        int hp;
        int attack;
    };

    typedef struct{
        String name;
        int hp;
        int attack;
    } Monster;

    typedef struct{
        String name;
        int hp;
        int attack;
    } Monster1;
    
    
    struct MONSTER seiryu = { "Seiryu1345", 30, 1000 };
    struct MONSTER suzaku = { .name = "Suzaku123", .hp = 50, .attack = 200 };
    struct MONSTER kyakko;
    struct MONSTER genbu;

    // printf("%s ", suzaku.name);
    // printf("%d ", suzaku.hp);
    // printf("%d ", suzaku.attack);

    // strcpy(suzaku.name, "Seiryu");
    // printf("%s ", suzaku.name);
    // printf("%d ", suzaku.hp);
    // printf("%d ", suzaku.attack);

    Monster seiryu1 = { "Seiryu1", 80, 15 };
    printf("%s ", seiryu1.name);
    printf("%d ", seiryu1.hp);
    printf("%d ", seiryu1.attack);

    // Monster1 seiryu2 = seiryu1;
    Monster seiryu2 = seiryu1;
    printf("\n%s ", seiryu2.name);
    printf("%d ", seiryu2.hp);
    printf("%d ", seiryu2.attack);

    // int S1 = GREEN;
    // printf("%d", S1);

    // printf("\n%d", Working);

    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

static inline int add(int a, int b){
    return a + b;
}

// typedef struct {
//     int hp;
//     char status;
// } Monster;

// enum { STATUS_POISON = 1, STATUS_SLEEP = 2, STATUS_SMALL = 4, STATUS_SILENT = 8 };

int main() {

    printf("%d\n", add(1,2));
    // Monster m;
    // m.hp = 100;
    // m.status = 0;

    // printf("Monster Poison\n");
    // m.status |= ~STATUS_POISON;

    // printf("Poison it work\n");
    // printf("if have poison Damage give 2\n");
    // if(m.status & STATUS_POISON) m.hp -= 2;
    // printf("Use [Kiseki no ishi]!\n");
    // printf("Poison or sleep HP will 100 Regen\n");
    // if(m.status & (STATUS_POISON | STATUS_SLEEP)) m.hp = 100;

	return 0;

}
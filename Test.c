#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

// typedef struct Monster
// {
//     String name;
//     int hp;
//     int attack;
// } Monster;

// void printMonsterSummary(Monster *m){
//     printf("Monster %s (HP = %d)", m->name, m->hp);
// }

// void ResultPointer(int *a){
//     printf("%d ", *a);
// }

// void funcA(int x){
//     x = 100;
// }

// void funcB(int *x){
//     x[0] = 100;
//     x[1] = 110;
//     x[2] = 120;
//     x[3] = 130;
//     x[4] = 140;
// }

// int* readyAges(void){
//     int ages[4];
//     return ages;
// }

// int *readyAges1(void){
//     int *ages = (int*) malloc(16);
//     return ages;
// }

// void sub(char ages[3]){
//     for(int i = 0; i < 3; i++){

//     }
// }

void add_array(int *p){
    printf("%d ", *p);
}

void myfunc(int *var1){
    for(int i = 0; i < 5; i++){
        printf("%d ", *var1);
        var1++;
    }
}

void myfunc1(int *var1, int i){
    printf("*pnum%d: %d    pnum%d(inum[%d] number address) : %p\n", (i + 1), *var1, (i + 1), i, var1);
}

void myfunc2(int *var1, int length){
    for(int i = 0; i < length; i++){
        printf("*pnum%d: %d    pnum%d(inum[%d] number address) : %p\n", (i + 1), *var1, (i + 1), i, var1);
        var1++;
    }
}

void myfunc3(char *var1, int i){
    printf("*pmoji%d[%d]: %c  pmoji[%d](cmoji%d[%d] number address): %p\n", (i + 1), i, *var1, i, (i + 1), i, var1);
}

void myfunc4(char *var1, int length){
    for(int i = 0; i < length; i++){
        printf("*pmoji%d[%d]: %c  pmoji[%d](cmoji%d[%d] number address): %p\n", (i + 1), i, *var1, i, (i + 1), i, var1);
        var1++;
    }
}

int main(){
    // Monster suzaku = { "Suzaku", 150, 80 };
    // printMonsterSummary(&suzaku); 

    // int a = 100;
    // int *pointer = &a;
    // ResultPointer(pointer);

    // int a = 100;
    // printf("Variable a have value 70 in inside variable\n");

    // int *addrA = &a;
    // printf("Variable a address is : %ld\n", addrA);

    // int *pointer;
    // pointer = &a;
    // printf("%d", *pointer);

    // int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // int *pointer = arr;
    // for(int i = 0; i < 10; i++){
    //     printf("%d ", pointer[i]);
    // }

    // char name[] = "Porndet Pipiptsuntonsan";

    // printf("%d ", strlen(name));

    // int a = 5;
    // int b[] = { 5 };

    // funcA(a);
    // funcB(b);

    // printf("a = %d,  b[0] = %d,  b[1] = %d,  b[2] = %d,  b[3] = %d,  b[4] = %d\n", a, b[0], b[1], b[2], b[3], b[4]);

    // int* a = readyAges1();
    // if(a == NULL){
    //     printf("Error");
    // }else{
    //     a[0] = 19;
    //     free(a);
    // }

    // int Tab[5] = { 100, 220, 37, 16, 98 };
    // myfunc(Tab);
    // for(int i = 0; i < 5; i++){
    //     add_array(&Tab[i]);
    // }

    int inum[] = { 1, 2, 3 };

    // int *pnum1;
    // int *pnum2;
    // int *pnum3;

    // pnum1 = &inum[0];
    // pnum2 = &inum[1];
    // pnum3 = &inum[2];

    // printf("*punm1: %d     pnum1(inum[0] number address) : %p", *pnum1, pnum1);
    // printf("\n*punm2: %d     pnum2(inum[1] number address) : %p", *pnum2, pnum2);
    // printf("\n*punm3: %d     pnum3(inum[2] number address) : %p", *pnum3, pnum3);

    int *pnum[3] = { &inum[0], &inum[1], &inum[2] };

    for(int i = 0; i < 3; i++){
        // myfunc1(pnum[i], i);
        // printf("*pnum%d: %d    pnum%d(inum[%d] number address) : %p\n", (i + 1), *pnum[i], (i + 1), i, pnum[i]);
    }
    // myfunc2(*pnum, 3);


    char charecterChar[] = { 'A', 'B', 'C', 'D', 'E' };

    char *pchar[] = { &charecterChar[0], &charecterChar[1], &charecterChar[2], &charecterChar[3], &charecterChar[4] };

    for(int i = 0; i < 5; i++){
        // myfunc3(pchar[i], i);
        // printf("\n*pmoji%d[%d]: %c  pmoji[%d](cmoji%d[%d] number address): %p", (i + 1), i, *pchar[i], i, (i + 1), i, pchar[i]);
    }

    myfunc4(*pchar, 5);

    // char *pchar1, *pchar2, *pchar3, *pchar4, *pchar5;

    // pchar1 = &charecterChar[0];
    // pchar2 = &charecterChar[1];
    // pchar3 = &charecterChar[2];
    // pchar4 = &charecterChar[3];
    // pchar5 = &charecterChar[4];

    // printf("*pmoji1[0]: %c  pmoji1[0](cmoji1[0] number address): %p", *pchar1, pchar1);
    // printf("\n*pmoji2[1]: %c  pmoji2[1](cmoji2[1] number address): %p", *pchar2, pchar2);
    // printf("\n*pmoji3[2]: %c  pmoji3[2](cmoji3[2] number address): %p", *pchar3, pchar3);
    // printf("\n*pmoji4[3]: %c  pmoji4[3](cmoji4[3] number address): %p", *pchar4, pchar4);
    // printf("\n*pmoji5[4]: %c  pmoji5[4](cmoji5[4] number address): %p", *pchar5, pchar5);

    return 0;
}
#include <stdio.h>
#include "TestHeaderfile.h"

#define MAXCNT 8

void func(int arg1){
    int var2;
    var2 = arg1;
}

void func1(int arg1){
    int i = 0;
    if(arg1){
        printf("%d", i);
    }
}

static int x;
// void func5(void){
//     x = 0;
// }

unsigned int flags;
void set_x_on(){
    flags |= 0x0F;
    printf("%d", flags);
}


int func3(int, int);
int func4(float, int);

int main(void){
    set_x_on();
    //1
    int var1;
    int x = 1;

    if(x == 1)
        func(x);

    /*
    * Comment
    * Comment
    * Comment
    */
   int cnt = 9;
   if(cnt == MAXCNT){

   }

   tag1.ab12 = 12;
   printf("\n%d", tag1.ab12);

   ab13 = 20;
   printf("\n%d", ab13);

    printf("\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr1[i][j]);
        }
    }
}


int func3(int x, int y){

}
int func4(float x, int y){

}
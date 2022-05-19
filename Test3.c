#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX 10
int stack[STACK_MAX]; //スタック 10 個まで
int stackTop = 0; //スタックの現在位置
//スタックにいれる
void pushStack(int val) {
    if (stackTop == STACK_MAX) {
        printf("error:stack overflow \n");
        exit(EXIT_FAILURE);
    } else
        stack[stackTop] = val;
        stackTop++;
}

int popStack() {
    if (stackTop == 0) {
        printf("error:stack is empty \n");
        exit(EXIT_FAILURE);
    } else
        stackTop--;
        return stack[stackTop];
}

void printStack() {
    printf(" Stack now \n");
    if (stackTop == 0) {
        printf(" Stack empty \n");
    } else{
        for(int i = stackTop - 1; i >= 0; i--){
            printf("#%0d# %d\n ", i, stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int buf = 1;
    while (buf != 0) {
        printf("Please put number 1-99 if you put number 0 program will end. \n>");
        scanf("%d", &buf);
        if (buf == 0) {
            break; //0 が入力されたら、 while 文を抜ける
        }
        pushStack(buf); // 入力された値をスタックに格納
        printStack(); // スタックの状態を表示
    }
    printf(" Display value take out from stack \n");
    while (stackTop > 0) {
        int popNum = popStack();
        printf(" Value take out \t%d\n", popNum);
        // printStack();// スタックの状態を表示
    }
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

void printbi(uint8_t n) {
    int i;
    for (i = 7; i >= 0; i--){
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    uint8_t a = 255;
    uint8_t b = 197;
    uint8_t c = 5;

    //1
    // printf("Before Caluculate a : ");
    // printbi(a);
    // printf("\nBefore Caluculate b : ");
    // printbi(b);
    // printf("\nAfter Calculate : ");
    // printbi(a & b);

    //2
    // printf("Before Caluculate a : ");
    // printbi(b);
    // printf("\nBefore Caluculate b : ");
    // printbi(c);
    // printf("\nAfter Calculate : ");
    // printbi(b ^ c);

    //3
    // printf("Before Caluculate a : ");
    // printbi(a);
    // printf("\nAfter Calculate : ");
    // printbi(~a);

    // printf("16 Bit : %X\n", a);
    // printf("10 Bit : %d\n", a);
    // printf("2 Bit : ");
    // printbi(a);
    // printf("\n\n");

    // printf("16 Bit : %X\n", b);
    // printf("10 Bit : %d\n", b);
    // printf("2 Bit : ");
    // printbi(b);
    // printf("\n\n");

    // printf("16 Bit : 0x%02x\n", c);
    // printf("10 Bit : %d\n", c);
    // printf("2 Bit : ");
    // printbi(c);
    // printf("\n");

	return 0;
}
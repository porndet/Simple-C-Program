#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

#define lengthArr 10

int main(void){
    // char *pointer[] = { "one", "two", "tree", "four", "five", "six", "seven", "eight", "nine", "ten" };
    // char *p1[1024];
    // int result;
    // for(int i = 0; i < 10; i++){
    //     for(int j = i + 1; j < 10; j++){
    //         result = strcmp(pointer[i], pointer[j]);
    //         // printf("(%s) - (%s) : %d\n",pointer[i], pointer[j], result);
    //         if(result == 1){
    //             p1[1024] = &pointer[i];
    //             pointer[i] = pointer[j];
    //             pointer[j] = p1[1024];
    //             // printf("(%s) - (%s) : %d\n",pointer[i], pointer[j], result);
    //         }
    //         // printf("(%s) - (%s) : %d\n",pointer[i], pointer[j], result);
    //     }
    //     printf("\n");
    // }

    // for(int i = 0; i < 10; i++){
    //     printf("%s ", pointer[i]);
    // }


    char *pointer[] = { "one", "two", "tree", "four", "five", "six", "seven", "eight", "nine", "ten" };
    char *p1;
    int result;

    // p1 = pointer[0]; //value
    // printf("%s  - %d\n", p1, &pointer[0]);

    for(int i = 0; i < lengthArr; i++){
        for(int j = i + 1; j < lengthArr; j++){
            result = strcmp(pointer[i], pointer[j]);
            // printf("(%s) - (%s) : %d\n",pointer[i], pointer[j], result);
            if(result == 1){
                p1 = pointer[i];
                pointer[i] = pointer[j];
                pointer[j] = p1;
                // printf("(%s) - (%s) : %d\n",pointer[i], pointer[j], result);
            }
            // printf("(%s) - (%s) : %d\n",pointer[i], pointer[j], result);
        }
        // printf("\n");
    }

    for(int i = 0; i < 10; i++){
        printf("%s ", pointer[i]);
    }

    return 0;
}
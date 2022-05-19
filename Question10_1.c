#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

void myfunc1(int *var1, int i){
    printf("*pnum%d: %d    pnum%d(inum[%d] number address) : %p\n", (i + 1), *var1, (i + 1), i, var1);
}

int main() {
    int inum[] = { 1, 2, 3 };
    int *pnum[3] = { &inum[0], &inum[1], &inum[2] };
    // for(int i = 0; i < 3; i++){
    //     myfunc1(pnum[i], i); 
    // }

    printf("Memory address of pnum2+1 = %p\n", pnum[1] + 1);
    printf("Value of pnum2+1 *(pnum2+1) = %d\n", *pnum[1] + 1);
    printf("Value of pnum2+1 = %d\n\n", pnum[2] + 1);

    printf("Memory address of pnum2+1 = %p\n", pnum[1]);
    printf("Value of pnum2+1 = %d\n", *pnum[1]);
    printf("Value of pnum2+1 = %d\n\n", pnum[2]);

    printf("Memory address of pnum2+1 = %p\n", pnum[1] - 1);
    printf("Value of pnum2+1 = %d\n", *pnum[1] - 1);
    printf("Value of pnum2+1 = %d", pnum[2] - 1);
	// int inum[] = {1,2,3};

	// int *pnum1;
	// int *pnum2;
	// int *pnum3;

	// pnum1= &inum[0];
	// pnum2= &inum[1];
	// pnum3= &inum[2];

    // printf("*pnum1: %d\tpnum1(inum[0]): %p\n",*pnum1,pnum1);
    // printf("*pnum2: %d\tpnum2(inum[1]): %p\n",*pnum2,pnum2);
    // printf("*pnum3: %d\tpnum3(inum[2]): %p\n",*pnum3,pnum3);
	
	return 0;

}
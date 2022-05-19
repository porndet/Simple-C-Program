#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

bool isTrue = true;

int main() {
    int result = 0;
    String Tensuu;

    while(isTrue){
        printf("3 Kamoku no tensuu wo nyuuryoku shitekudasai\n");
        for(int i = 0; i <= 2; i++){
            (i == 0)? printf("Kokugo : ") : (i == 1)? printf("Suugaku : ") : printf("Eigo : ");
            scanf("%s", Tensuu);
            if(atoi(Tensuu) >= 101){
                printf("100 ika no suuji wo nyuuryokushitekudasai.\n\n");
                isTrue = false;
                return 0;
            }else{
                result += atoi(Tensuu);
            }
        }

        double heikin = (double) result / 3;
        printf("Heikinten %.1f ten desu.\n", heikin);
        result = 0;

        if((int)heikin == 100)
            printf("Mantendesu! subarashii seisekidesu.\n\n");
        else if((int)heikin >= 80 && (int)heikin <= 99)
            printf("Taihen yokudekimashita.\n\n");
        else if((int)heikin >= 60 && (int)heikin <= 79)
            printf("Yoku dekimashita.\n\n");
        else
            printf("Mousukoshi ganbarimashou.\n\n");
    }
    return 0;
}
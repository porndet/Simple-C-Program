#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

int main() {
    String Numbernichi;
    printf("Kyouwa shigatsu no nannichi desuka : ");
    scanf("%s", Numbernichi);
    int Nannichi = atoi(Numbernichi);

    if(Nannichi == 0 || Nannichi >= 31){
        printf("1-30 Nyuuryoku kudasai.\n");
        return 0;
    }else{
        switch (Nannichi % 7)
        {
            case 1:
                printf("4 gatsu %d Nichi Kinyoubi\n", Nannichi);
                break;
            case 2:
                printf("4 gatsu %d Nichi Doyoubi\n", Nannichi);
                break;
            case 3:
                printf("4 gatsu %d Nichi Nichiyoubi\n", Nannichi);
                break;
            case 4:
                printf("4 gatsu %d Nichi Getsuyoubi\n", Nannichi);
                break;
            case 5:
                printf("4 gatsu %d Nichi Kayoubi\n", Nannichi);
                break; 
            case 6:
                printf("4 gatsu %d Nichi Suiyoubi\n", Nannichi);
                break; 
            case 0:
                printf("4 gatsu %d Nichi Mokuyoubi\n", Nannichi);
                break;
            default:
                break;
        }
        return 0;
    }
}
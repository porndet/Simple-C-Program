#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

int OutputYear(){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    int tempyear =  tm.tm_year + 1900;
    return tempyear;
}

int AtoiScanf(String text){
    String tempMonthDay;
    printf("%s", text);
    scanf("%s", tempMonthDay);
    return atoi(tempMonthDay);
}

int Checkmonth(int month){
    if(month > 0 && month <= 12){
        return 1;
    }else{
        return 0;
    }
}

int Checkday(int day, int month){
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day > 0 && day <= 31)
                return 1;
            else
                return 0;
        break;

        case 2:
            if(OutputYear() / 4 == 502){
                if(day > 0 && day <= 29)
                    return 1;
                else
                    return 0;
            }else{
                if(day > 0 && day <= 28)
                    return 1;
                else
                    return 0;
            }
        break;

        case 4: case 6: case 9: case 11:
            if(day > 0 && day <= 30)
                return 1;
            else
                return 0;
        break;

        default:
        break;
    }
}

typedef struct Rensyuu
{
    String name;
    int month;
    int day;
} Rensyuu;


/* （ヒント）                                 */
/* 1. 牡羊座(3月21日～4月19日)                */
/* 2. 牡牛座(4月20日～5月20日)                */
/* 3. 双子座(5月21日～6月21日)                */
/* 4. 蟹座(6月22日～7月22日)                  */
/* 5. 獅子座(7月23日～8月22日)                */
/* 6. 乙女座(8月23日～9月22日)                */
/* 7. 天秤座(9月23日～10月23日)               */
/* 8. さそり座(10月24日～11月22日)            */
/* 9. 射手座(11月23日～12月21日)              */
/*10. 山羊座(12月22日～1月19日)               */
/*11. 水瓶座(1月20日～2月18日)                */
/*12. 魚座(2月19日～3月20日)                  */

int main() {
    Rensyuu r;
    printf("You name : ");
    scanf("%s", r.name);

    r.month = AtoiScanf("You birthday month : ");
    r.day = AtoiScanf("You birthday day : ");

    if(Checkmonth(r.month)){
        if(Checkday(r.day, r.month)){
            if(r.month == 1){ 
                if(r.day <= 19){
                    printf("10");
                }else{
                    printf("11");
                }
            }else if(r.month == 2){
                if(r.day <= 18){
                    printf("11");
                }else{
                    printf("12");
                }
            }else if(r.month == 3){
                if(r.day >= 21){
                    printf("1");
                }else{
                    printf("12");
                }
            }else if(r.month == 4){
                if(r.day <= 19){
                    printf("1");
                }else{
                    printf("2");
                }
            }else if(r.month == 5){
                if(r.day <= 20){
                    printf("2");
                }else{
                    printf("3");
                }
            }else if(r.month == 6){
                if(r.day <= 21){
                    printf("3");
                }else{
                    printf("4");
                }
            }else if(r.month == 7){
                if(r.day <= 22){
                    printf("4");
                }else{
                    printf("5");
                }
            }else if(r.month == 8){
                if(r.day <= 22){
                    printf("5");
                }else{
                    printf("6");
                }
            }
            else if(r.month == 9){
                if(r.day <= 22){
                    printf("6");
                }else{
                    printf("7");
                }
            }
            else if(r.month == 10){
                if(r.day <= 23){
                    printf("7");
                }else{
                    printf("8");
                }
            }
            else if(r.month == 11){
                if(r.day <= 22){
                    printf("8");
                }else{
                    printf("9");
                }
            }
            else if(r.month == 12){
                if(r.day <= 21){
                    printf("9");
                }else{
                    printf("10");
                }
            }
        }
        else{
            printf("You input number day wrong");
            return 0;
        }
    }else{
        printf("You input number month wrong");
        return 0;
    }
}
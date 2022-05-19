#include <stdbool.h>
#include <time.h>
#define GuessNumber 3

typedef char String[1024];
int answer[3], input[3];
bool check;
int hit = 0, blow = 0;

void DisplayFirstPrint(void){
    printf("*** Guess number game (Level 2) ***\n");
    printf("Please guess number correct in 3 number\n");
    printf("But each number will unique\n");
}

const int RandomNum(){
    return rand() % 10;
}

void Random_ThreeNumber(int i){
    do{
        answer[i] = RandomNum();
        for(int j = 0; j < i; j++){
            check = false;
            if(answer[i] == answer[j]){
                break;
            }
            check = true;
        }
    }while(i > 0 && check == false);
}

const int Intprintf(){
    int inputUser;
    scanf("%d", &inputUser);
    return inputUser;
}

void HitBlowCount(){
    for(int i = 0; i < GuessNumber; i++){
        if(input[i] == answer[i]){
            hit++;
        }
        for(int j = 0; j < GuessNumber; j++){
            if(input[i] == answer[j] && i != j){
                blow++;
            }
        }
    }
    printf("%d Hit! %d Blow !\n", hit, blow);
}

const int AnswerCorrect(){
    if(hit == GuessNumber){
        printf("Correct\n");
        return 1;
    }else{
        return 0;
    }
}

void LookanswerRandom(void){
    printf("Answer Correct ");
    for(int i = 0; i < GuessNumber; i++){
        printf("%d", answer[i]);
    }
}

const int PlayContinue(){
    printf("Will play continue? (0 will be end program but not 0 will play continue) : ");
    return Intprintf();
}

void mainFunction(){
    srand(time(NULL));
    DisplayFirstPrint();
    for(int i = 0; i < GuessNumber; i++){
        Random_ThreeNumber(i);
    }
    
    do{
        for(int i = 0; i < GuessNumber; i++){ 
            printf("(%d) Please put guess number 0~9 : ", i + 1);
            input[i] = Intprintf();
        }

        HitBlowCount();

        if(AnswerCorrect() == 1){
            break;
        }else{
            if(PlayContinue() == 0){
                LookanswerRandom();
                break;
            }
        }
    }while(true);
}
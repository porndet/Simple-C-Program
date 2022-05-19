#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
// #include <stdbool.h>

// typedef enum {false, true} bool;
typedef enum { F, T } boolean;

struct Manager {
   int Calculate_First;
   int Calculate_Two;
} STRCalculate;

struct KeisanBun{
   int a;
   int b;
} Keisan;

void calculate(int x, int y){
   printf("Calculate : 29 + 29 = %d\n", x + y);
   // return x + y;
}

int valuex(){
   const int x = 6;
   return x * x * 3;
}

enum State {WORKING = 0, FAILED, FREEZED};
enum State currState = 2;
  
enum State FindState() {
    return currState;
}

void Keisanbun(){
   Keisan.a = 20;
   Keisan.b = Keisan.a + 5;
   printf("%d\n", Keisan.a);
   printf("%d\n", Keisan.b);
}

typedef char String[1024];

int main() {   
   calculate(29, 29);
   // printf("Calculate : 29 + 29 = %d\n", calculate(29, 29));
   printf("Value X : %d\n", valuex());

   struct Manager Calculate;
   Calculate.Calculate_First = 29;
   printf("%d\n", Calculate.Calculate_First);

   STRCalculate.Calculate_Two = 50;
   printf("%d\n", STRCalculate.Calculate_Two);

   // bool x = True;
   // if(x){
   //    printf("X Working");
   // }else{
   //    printf("X Not Working");
   // }

   boolean x = F;
   (x)? printf("X Working\n") : printf("X Not Working\n");

   // enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
   // enum day d = sunday;
   // printf("\nThe day number stored in d is %d", d);

   // enum State {Working = 1, Failed = 0, Freezed = 0};
   // printf("\n%d, %d, %d", Working, Failed, Freezed);

   enum day {sunday, tuesday, wednesday, thursday, friday, saturday};
   enum day d = thursday;
   printf("The day number stored in d is %d", d);

   (FindState() == WORKING)? printf("\nWORKING"): printf("\nNOT WORKING");

   String name = "\nPorndet Pipitsuntonsan";
   printf("%s", name);

   char myname[100] = "Porndet Pipitsuntonsan";
   printf("\n%s", myname);

   int a = 0x1F;
   printf("\n%d", a);

   int x1;
   printf("%d\n", x1);


   int age = 20;
   printf("Am Age : %d\n", age);
   age = 31;
   printf("Reality Age : %d\n", age);


   int tax = 110;
   int fax = 50000;
   printf("50000 yen kara 40000 yen ni chisageshimasu\n");
   tax = 40000;
   printf("FAX no shinkaggaku (seikin) : %d yen\n", fax * tax / 100);
   
   Keisanbun();

   printf("Watashi no sukinamono wa dango\"desu");

   printf("\nc:\\misaki\\document\\Mydiary.c\n");

   float f = 3;
   double b = f;
   printf("%f\n", f);
   printf("%f", b);

   int i = 3.2;
   printf("\n%d\n", i);

   double d1 = 8.5 /2;
   long l = 5 + 2L;
   printf("%f\n", d1);
   printf("%ld\n", l);

   int age1 = 29;
   printf("Kotoshi %d sai de\n", age1);
   int newAge = age1 + 1;
   printf("Mirai %d sai desu\n", newAge);

   String age2 = "29";
   int n = atoi(age2);
   printf("%d", n);

   srand(time(NULL));
   int r = rand() % 100;
   printf("\nRandom Number %d", r);

   bool tenki = false;
   (tenki)? printf("\nSentakushimasu\n"), printf("Sanbo ni ikimasu") : printf("\nEiga o mimasu\n");
   // if(tenki){
   //    printf("\nSentakushimasu\n");
   //    printf("Sanbo ni ikimasu");
   // }else{
   //    printf("\nEiga o mimasu");
   // }
   // bool doorclosed = true;
   // while(doorclosed){
   //    printf("Nokkusuru\n");
   //    printf("1 bun matsu\n");
   // }

   String pref = "Kumamoto";
   if(strcmp(pref, "Kumamoto") == 0)
      printf("Seikai");
   else
      printf("Fuseikai");
   // printf("%d", strcmp(pref, "Kumamoto1"));

   char name2[100] = "\nPorndet Pipitsuntonsan\n";
   printf("%s", name2);

   int x2 = 5;
   int y2 = 6;
   (x2 != y2)? printf("Not equal") : printf("Equal");
   

	enum Kichi { DAIKICHI = 1, CHUKICHI, KICHI };

	printf("Anata no unsei wo uranai masu");
	srand((unsigned)time(NULL));
	int forture = rand() % 4 + 1;
	printf(" Number : %d\n", forture);

	switch (forture)
	{
		case DAIKICHI:
			printf("Daikichi\n");
			break;
		case CHUKICHI:
			printf("Chuukichi\n");
			break;
		case KICHI:
			printf("Kichi\n");
			break;
		default:
			printf("Ku\n");
	}

   for(int i = 0; i < 10; i++){
      printf("Konichiwa %d\n", i);
   }
   
   for(int i = 1; i <= 3; i++){
      printf("Gensai %d Shuume desu\n", i);
   }

   for(int i = 1; i < 10; i++){
      for(int j = 1; j < 10; j++){
         printf("%2d ", i * j);
      }
      printf("\n");
   }

   int Toshitama = 3000;
   int roundX = 0;
   printf("Ringo : ");
   while(Toshitama >= 120){
      printf("*");
      Toshitama -=  120;
      roundX++;
   }
   // printf("%d", roundX);
   printf(" Amari wa %d yen", Toshitama);

   Toshitama = 3000;
   roundX = 0;
   printf("\nMikan : ");
   while(Toshitama >= 400){
      for(int i = 0; i < 6; i++){
         printf("*");
         roundX++;
      }
      Toshitama -=  400;
   }
   printf(" Amari wa %d yen", Toshitama);
   return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

/******************************************************/
/* 三角形、正方形、円を与えられた個数だけ出力します。 */
/* 図は文字で”△”、”□”、”○”と表示します。     */
/* まず図形を表す構造体を定義し、表示文字と個数を     */
/* 代入するフィールドを作成します。                   */
/* 三角形、正方形、円はそれぞれ構造体変数とします。   */
/*                                                    */
/* （実行例）                                         */
/* 三角形の個数：2                                    */
/* 正方形の個数：3                                    */
/* 円の個数：5                                        */
/* △△□□□○○○○○                               */
/*                                                    */
/******************************************************/

int main() {
    String Tri, Rec, Cir;

    printf("Triangle : ");
    scanf("%s", Tri); 

    printf("Rectangle : ");
    scanf("%s", Rec); 

    printf("Circle : ");
    scanf("%s", Cir); 

    for(int i = 0; i < atoi(Tri); i++){
        printf("△");
    }

    for(int i = 0; i < atoi(Rec); i++){
        printf("□");
    }

    for(int i = 0; i < atoi(Cir); i++){
        printf("*");
    }
}
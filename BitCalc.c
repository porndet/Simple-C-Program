#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

void printbi(uint8_t n){
    int i;
    for(i = 7; i >= 0; i--){
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    unsigned int itemno = 0; //商品番号
    // シフト用
    //32 มาจาก ใช้ไป 32 บิต 4 + 9 + 3 + 16 = 32
    const int categoryshift = 28; //カテゴリID抽出用シフトビット数 32-4=28 
    const int itemshift = 19; //商品ID抽出用シフトビット数 32-(4+9)=19
    const int typeshift = 16; //商品分類抽出用シフトビット数 32-(4+9+3)=16
    // 32ビットマスク用
    unsigned int categorymask = 0xf; //カテゴリID用4ビットのマスクパターン ใช้ไป 4 บิต
    unsigned int itemmask = 0x1ff; //商品ID用9ビットのマスクパターン ใช้ไป 9 บิต
    unsigned int typemask = 0x7; //商品分類用3ビットのマスクパターン ใช้ไป 3 บิต
    unsigned int pricemask = 0xffff; //価格用16ビットのマスクパターン ใช้ไป 16 บิต
    printf("Category ID : Please put number 0 ~ 15\n>");
    unsigned int categoryid = 0;
    scanf("%d", &categoryid);
    printf("Goods ID :Please put number  0 ~ 511 \n>");
    unsigned int itemid = 0;
    scanf("%d", &itemid);
    //1:受注扱、2:季節、3:在庫処分、4:廃盤
    printf("Please number 1. 2. 3. 4\n>");
    unsigned int itemtype = 0;
    scanf("%d", &itemtype);
    printf("Please put number 0 yen ~ 65535 yen\n>");
    unsigned int price = 0;
    scanf("%d", &price);
    //入力された情報から商品番号を生成
    itemno = (categoryid << categoryshift) + (itemid << itemshift)
    + (itemtype << typeshift) + price;
    printf("Goods number to put from user : %u\n", itemno);
    //マスク処理 商品番号から各情報を抽出 ビットシフト後、AND演算
    printf("Category ID : %u\n", (itemno >> categoryshift)& categorymask);
    printf("Goods number ID : %u\n", (itemno >> itemshift)& itemmask);
    printf("Type of goods : %u\n", (itemno >> typeshift) & typemask);
    printf("Price : %u\n", (itemno & pricemask));
	return 0;

}
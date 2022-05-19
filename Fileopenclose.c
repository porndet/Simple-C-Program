#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[1024];

typedef struct {
    char name[16];
    int height;
    double sight;
}Csv;

#define CTRL(x) (#x[0]-'a'+1)

int main() {
    // FILE* fp;
    // fp = fopen("memo.txt", "r");

    // if(fp == NULL){
    //     printf("File not open");
    // }else{
    //     printf("File open");
    // }

    // fclose(fp);

    // FILE* fp;
    // char text[] = "sukkriC!";
    // int len = strlen(text);
    // int ch;

    // if((fp = fopen("memo.txt", "w")) == NULL){
    //     exit(1);
    // }

    // for(int i = 0; i < len; i++){
    //     fputc(text[i], fp);
    // }
    // fclose(fp);

    // if((fp = fopen("memo.txt", "r")) == NULL){
    //     exit(1);
    // }

    // while((ch = fgetc(fp)) != EOF){
    //     putchar((char)ch);
    // }

    // fclose(fp);

    // FILE * fp;
    // char wbuf[64];

    // if((fp = fopen("memo.txt", "w")) == NULL){
    //     exit(1);
    // }else{
    //     fputs("government of the people, \nby the people, \nfor the people", fp);
    //     fclose(fp);
    // }

    // if((fp = fopen("memo.txt", "r")) == NULL){
    //     exit(1);
    // }else{
    //     if(fgets(wbuf, 64, fp) != NULL){
    //         printf("%s", wbuf);
    //     }
    //     fclose(fp);
    // }

    // FILE* fp;
    // char filename[] = "data.csv";

    // Csv data[3] = {
    //     {"Kaitou", 180, 1.5}, //17
    //     {"Misaki", 173, 0.6}, //17
    //     {"Akagi", 161, 1.0} // 16
    // };

    // if((fp = fopen(filename, "w")) == NULL){
    //     exit(1);
    // }

    // for(int i = 0; i < 3; i++){
    //     int cn = fprintf(fp, "%s, %d, %4.2f\n", data[i].name, data[i].height, data[i].sight);
    //     if(cn < 0){
    //         printf("Failed Write");
    //         fclose(fp);
    //         exit(1);
    //     }else{
    //         printf("%s-san : %d Write to file Success\n", data[i].name, cn);
    //     }
    // }

    // fclose(fp);

    // FILE* fp;
    // char wbuf[] = "012345678901";
    // char rbuf[16];

    // if((fp = fopen("try.dat", "wb")) == NULL){
    //     exit(1);
    // }else{
    //     fwrite(wbuf, 11, 1, fp);
    //     fclose(fp);
    // }

    // if((fp = fopen("try.dat", "rb")) == NULL){
    //     exit(1);
    // }else{
    //     int cn = fread(rbuf, 1, 11, fp);
    //     rbuf[11] = '\0';
    //     fclose(fp);
    //     printf("Read data of %d : %s\n", cn, rbuf);
    // }

    // FILE* fp;
    // char header[54] = { 0 };
    // char image[192] = { 0 };

    // header[0] = 66;
    // header[1] = 77;

    // int* di;
    // di = (int*)(header + 2);
    // *di = 246;
    // di = (int*)(header + 10);
    // *di = 54;
    // di = (int*)(header + 14);
    // *di = 40;
    // di = (int*)(header + 18);
    // *di = 8;
    // di = (int*)(header + 20);
    // *di = 8;

    // short* ds;
    // ds = (short*)(header + 26);
    // *ds = 1;
    // ds = (short*)(header + 28);
    // *ds = 24;

    // for(int i = 0; i < 192; i += 3){
    //     image[i] = -1;
    //     image[i + 1] = 0;
    //     image[i + 2] = 0;
    // }

    // if((fp = fopen("bluebox.jpg", "wb")) == NULL){
    //     exit(1);
    // }else{
    //     fwrite(header, 54, 1, fp);
    //     fwrite(image, 192, 1, fp);
    //     fclose(fp);
    // }

    FILE* fp;
    char arr[100];
    char c;
    int i = 0;
    //0x1A

    printf("Please put character ");
    if((fp = fopen("memo.txt", "w")) == NULL){
        exit(1);
    }else{
        while((c  = getchar()) != EOF){
            arr[i] = c;
            i++;
        }
    }

    for(int x = 0; x < i; x++){
        fputc(arr[x], fp);
    }

	return 0;

}
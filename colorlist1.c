#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef char String[1024];

typedef struct colorlist
{
    String color;
    char fruits[50][100];
    int lengthfruits;
    struct colorlist *next;
} colorlist;


int main(void){
    colorlist* headnode = NULL;
    colorlist* newnode = NULL;
    colorlist* tailnode = NULL;
    String color;
    int i = 1;


    while(!strcmp(color, "0") == 0){
        printf("Color %d > ", i);
        scanf("%s", color);

        if(strcmp(color, "0") == 0){
            break;
        }
        
        newnode = (colorlist*)malloc(sizeof(colorlist));

        newnode->lengthfruits = 0;
        strcpy(newnode->color, color);
        newnode->next = NULL;
        int j = 1;
        String fruits = "1";

        while(!strcmp(fruits, "0") == 0){
            printf("     fruit %d >> ", j);
            scanf("%s", fruits);

            if(strcmp(fruits, "0") == 0){
                break;
            }else{
                strcpy(newnode->fruits[newnode->lengthfruits], fruits);
                newnode->lengthfruits++;
                j++;
            }
        }

        if(tailnode == NULL){
            headnode = newnode;
        }else{
            tailnode->next = newnode;
        }
        tailnode = newnode;
        i++;
    }

    colorlist* thisnode = NULL;

    String inputcolor;
    bool isTrueNode = true;
    int x = 1;

    printf("input color > ");
    scanf("%s", inputcolor);

    for(thisnode = headnode; thisnode != NULL && isTrueNode; thisnode = thisnode->next, x++){
        if(strcmp(thisnode->color, inputcolor) == 0){
            printf("%s/", thisnode->color);
            for(int i = 0; i < thisnode->lengthfruits; i++){
                printf("%s ", thisnode->fruits[i]);
            }
            isTrueNode = false;
            break;
        }else{
            if(x == (i - 1)){
                printf("Sorry... %s is not color list.", inputcolor);
                isTrueNode = false;
                break;            
            }            
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    char b;
} tipo;

int main(void){
    tipo str[7][3][2][4];
    printf("%lu", sizeof(str));
}
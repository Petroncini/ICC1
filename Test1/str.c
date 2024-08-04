#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Ponto;

Ponto func(void);

int main(void){
    Ponto p;
    p.x = 1;
    p.y = 2;

    p = func();

    printf("%d %d", p.x, p.y);
}

Ponto func(void){
    Ponto p;
    p.x = 2;
    p.y = 2;
    return  p;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
} fracao;

int main(void){
    fracao a, b;
    scanf("%d %d", &a.num, &a.den);
    scanf("%d %d", &b.num, &b.den);

    printf("mult: %d/%d\n", a.num * b.num, a.den * b.den);
    printf("div: %d/%d\n", a.num * b.den, a.den * b.num);
    printf("soma: %d/%d\n", (a.num * b.den) + (b.num * a.den), a.den * b.den);
    printf("sub: %d/%d\n", (a.num * b.den) - (b.num * a.den), a.den * b.den);

}
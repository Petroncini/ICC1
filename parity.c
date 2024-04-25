#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);

    if(a%2 == b%2){
        if(a%2==0){
            printf("a é par\nb é par\no produto de a e b é %i, que é par\n", a*b);
        } else {
            printf("a é impar\nb é impar\no produto de a e b é %i, que é impar\n", a*b);
        }
    } else {
        if(a%2==0){
            printf("a é par\nb é impar\na soma de a e b é %i, que é impar\n", a+b);
        } else {
            printf("a é impar\nb é par\na soma de a e b é %i, que é impar\n", a+b);
        }
    }
}
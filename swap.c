#include <stdio.h>

int main(void){
    int a, b, c, temp;
    scanf("%i %i %i", &a, &b, &c);

    for(int i = 0; i < 2; i++){
        if(b < a){
            temp = a;
            a = b;
            b = temp;
        }
        if(c < b){
            temp = b;
            b = c;
            c = temp;
        }
    }

    printf("%i %i %i\n", a, b, c);
}
#include <stdio.h>

int main(void){
    float x, y;
    scanf("%f %f", &x, &y);
    
    if((y <= 3*x && y >= x/3)||(y >= 3*x && y <= x/3)){
        printf("INTERIOR");
    } else {
        printf("EXTERIOR");
    }
}
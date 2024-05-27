#include <stdio.h>

int main(void){
    float m;
    int seconds = 0;
    scanf("%f", &m);

    printf("Massa inicial: %f, ", m);

    while(m >= 0.5){
        seconds += 50;
        m /= 2;
    }

    int hours = seconds/3600;
    seconds %= 3600;
    int minutes = seconds/60;
    seconds %= 60;

    printf("massa final: %f, horas %i, minutos: %i, segundos: %i\n", m, hours, minutes, seconds);
}
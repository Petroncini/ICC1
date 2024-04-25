#include <stdio.h>

int main(){
    float ini, decai;
    int segundos = 0;
    scanf("%f", &ini);
    decai = ini;

    while(decai > 0.5){
        decai /= 2;
        segundos += 50;

        printf("Meia vida: %i, massa: %f\n", segundos/50, decai);

    }
    int horas = segundos / 3600;
    segundos %= 3600;
    int minutos = segundos / 60;
    segundos %= 60;
    
    printf("Massa inicial: %f, horas: %i, minutos: %i, segundos: %i\n", ini, horas, minutos, segundos);
    
}

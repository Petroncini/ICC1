#include <stdio.h>
#include <stdlib.h>

double* allocate(int size);

int main(void){
    int n;
    scanf("%d", &n); // recebe do usuário o temnho desejado para o vetor

    double * array = allocate(n);

    free(array);
}

double* allocate(int size){ // essa função recebe o tamanho do vetor que deve ser alocado e retorna um ponteito para esse array;
    return malloc(sizeof(double) * size);
}
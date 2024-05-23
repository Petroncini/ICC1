#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void allocate(int ***mat, int n);
void enter(int **arr, int n);
void print(int **arr, int n);

int main(void){
    int n;
    scanf("%d", &n); // recebe do usuário o temnho desejado para o vetor
    n = sqrt(n);

    int **array = NULL;
    allocate(&array, n);
    enter(array, n);
    print(array, n);

    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);
    
}

void allocate(int ***mat, int n){ // essa função recebe o tamanho do vetor que deve ser alocado e retorna um ponteito para esse array;
    *mat = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        (*mat)[i] = malloc(sizeof(int) * n);
    }
}

void enter(int **arr, int n){ // recebe n valores e colocar eles em um vetor
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        
    }
}

void print(int **arr, int n){ // imprime os valores de um vetor double
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
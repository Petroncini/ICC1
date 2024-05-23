#include <stdio.h>
#include <stdlib.h>

double** allocate(int m, int n);
void enter(double **arr, int m, int n);
void print(double **arr, int m, int n);

int main(void){
    int m, n;
    scanf("%d %d",&m, &n); // recebe do usuário o temnho desejado para o vetor

    double **array = allocate(m, n);
    enter(array, m, n);
    print(array, m, n);
    free(array);
}

double** allocate(int m, int n){ // essa função recebe o tamanho do vetor que deve ser alocado e retorna um ponteito para esse array;
    double **mat = malloc(sizeof(double*) * m);
    for (int i = 0; i < m; i++)
    {
        mat[i] = malloc(sizeof(double) * n);
    }
    return mat;
}

void enter(double **arr, int m, int n){ // recebe n valores e colocar eles em um vetor
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &arr[i][j]);
        }
        
    }
}

void print(double **arr, int m, int n){ // imprime os valores de um vetor double
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }
}
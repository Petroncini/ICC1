#include <stdio.h>

void media_alunos(int n, int m, float notas[100][25]);
void media_exercicios(int n, int m, float *medias_exec,  float notas[100][25]);
void sort(int n, float *arr);

int main(void){
    int n, m;
    float notas[100][25];
    float medias_exec[25];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%f", &notas[i][j]);
        }
        
    }

    media_alunos(n, m, notas);
    media_exercicios(n, m, medias_exec, notas);

    sort(m, medias_exec);

    printf("\n");

    for (int i = 0; i < m; i++)
    {
        printf("%.2f ", medias_exec[i]);
    }

    printf("\n");
    
}

void media_alunos(int n, int m, float notas[100][25]){
    for (int i = 0; i < n; i++)
    {
        float soma_aluno = 0;
        for (int j = 0; j < m; j++)
        {
            soma_aluno += notas[i][j];
        }
        printf("Media do aluno %d = %.2f : ", i + 1, soma_aluno/m);

        if(soma_aluno/m >= 5){
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }
}

void media_exercicios(int n, int m, float *medias_exec,  float notas[100][25]){
    for (int j = 0; j < m; j++)
    {
        float soma_exercicio = 0;
        for (int i = 0; i < n; i++)
        {
            soma_exercicio += notas[i][j];
        }
        medias_exec[j] = soma_exercicio/n;
    }
}

void sort(int n, float *arr){
    int swap = 1;
    while(swap){
        swap = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if(arr[i] < arr[i + 1]){
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = 1;
            }
        }
    }
}

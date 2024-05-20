#include <stdio.h>

void fill(int n, int mat[20][20]);
int diagonal(int n, int mat[20][20]);
void mult(int n, int mat1[20][20], int mat2[20][20]);
void redpill(int n, int mat[20][20]);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int mat1[20][20];
    int mat2[20][20];

    fill(n, mat1);
    fill(m, mat2);

    printf("Matrizes:\n");
    redpill(n, mat1);
    redpill(m, mat2);

    if(diagonal(n, mat1)){
        printf("A matriz 1 eh diagonal\n");
    } else {
        printf("A matriz 1 nao eh diagonal\n");
    }

    if(diagonal(m, mat2)){
        printf("A matriz 2 eh diagonal\n");
    } else {
        printf("A matriz 2 nao eh diagonal\n");
    }

    if(n != m){
        printf("Matrizes de tamanho incompativel\n");
    } else {
        printf("Matriz multiplicada:\n");
        mult(n, mat1, mat2);
    }

}

void redpill(int n, int mat[20][20]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void fill(int n, int mat[20][20]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int diagonal(int n, int mat[20][20]){
    int diag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(i != j){
                if(mat[i][j] != 0){
                    diag = 0;
                }
           }
        }
    }
    return diag;
}

void mult(int n, int mat1[20][20], int mat2[20][20]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int mul = 0;

            for (int k = 0; k < n; k++)
            {
                mul += mat1[i][k] * mat2[k][j];
            }

            printf("%d ", mul);
        }

        printf("\n");
    }
}
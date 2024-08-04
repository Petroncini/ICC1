#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transpose(int **mat, int n, int m);
void freeMatrix(int ***mat, int n, int m);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int **mat = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        mat[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
        
    }
    
    transpose(mat, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    freeMatrix(&mat, n, m);
    
}

void transpose(int **mat, int n, int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
        
    }
    
}

void freeMatrix(int ***mat, int n, int m){
    for (int i = 0; i < n; i++)
    {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
}
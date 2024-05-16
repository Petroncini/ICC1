#include <stdio.h>

void enter_sandman(int m, int n, double **mat);
void redpill(int m, int n, double **mat);

int main(void){
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d %d\n", m, n);
    double mat[100][100];
    enter_sandman(m, n, mat);
    redpill(m, n, mat);

    



}

void enter_sandman(int m, int n, double **mat){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("i: %d, j: %d\n", i, j);
            scanf("%lf", &mat[i][j]);
            printf("%lf\n", mat[i][j]);
        }
        
    }
}

void redpill(int m, int n, double **mat){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int *mat = malloc((n * m) * sizeof(int));
    int **matp = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matp[i] = mat + i*n;
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matp[i][j]);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matp[i][j]);
        }
        printf("\n");
    }

    free(mat);
    free(matp);
    
}
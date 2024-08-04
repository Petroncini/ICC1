#include <stdio.h>
#include <stdlib.h>

int *intercalate(int *a, int *b, int n, int m);

int main (void){
    int n, m;
    scanf("%d %d", &n, &m);

    int *a = malloc(n * sizeof(int));
    int *b = malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", b + i);
    }

    printf("intercalating...\n");
    int *c = intercalate(a, b, n, m);

    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    
}

int *intercalate(int *a, int *b, int n, int m){
    int *c = malloc((n + m) * sizeof(int));

    int i = 0, j = 0, k = 0;
    while(i < n || j < m){
        if(i < n){
            c[k++] = a [i];
        }

        if(j < m){
            c[k++] = b [j];
        }

        if(i < n){
            i++;
        }

        if(j < m){
            j++;
        }

    }
    return c;
}
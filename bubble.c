#include <stdio.h>

void swap(int *a, int *b);

int main(void){
    int n;
    int vet[10000];
    int temp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", vet + i);
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if(vet[i] > vet[i + 1]){
                swap(vet + i, vet + i + 1);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
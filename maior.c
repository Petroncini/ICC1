#include <stdio.h>

int main(void){
    int n;
    float vec[10000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", vec + i);
    }
    
    float maior = vec[0];

    for (int i = 0; i < n; i++)
    {
       if(vec[i] > maior){
            maior = vec[i];
       }
    }
    
    printf("%f", maior);
}
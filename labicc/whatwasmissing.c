#include <stdio.h>

void sort(int *arr, int n);

int main(void){
    double n;
    int arr[200000];
    scanf("%lf", &n);
    n--;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    
    long long int expected_sum = ((n + 1)/2)*(n + 2);
    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
   
    printf("Numero desaparecido: %lld", expected_sum - sum);
    
    
}


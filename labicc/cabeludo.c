#include <stdio.h>

void swap(int *a, int *b);

int main(void){
    int vet[100000];
    int fib[100000];
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    int fib_n = 3;

    while(fib[fib_n - 1] < 2000){
        fib[fib_n] = fib[fib_n - 1] + fib[fib_n - 2];
        fib_n++;
    }

    


    int size = 0;
    int *vp;
    vp = vet;
    
    do{
        scanf("%d", vet + size++);
    } while(vet[size - 1] != 1);
    size--;

    char op;
    scanf(" %c", &op);
    int swapped = 1;

    if(op == 'a'){
        while (swapped)
        {
            swapped = 0;
            for (int i = 0; i < size - 1; i++)
            {
                if(vet[i] > vet[i + 1]){
                    swap(vet + i, vet + i + 1);
                    swapped = 1;
                }
            }
        }
        printf("vetor ordenado:");
        for (int i = 0; i < size; i++)
        {
            printf("%i ", vet[i]);
        }
        printf("\n");
        
    } else if(op == 'b'){
        printf("Numeros de Fibonacci:");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < fib_n; j++)
            {
                if(vet[i] == fib[j]){
                    printf("%d ", vet[i]);
                    break;
                }
            }
            
        }
        printf("\n");
        
    } else if(op == 'c'){
        printf("Vetor maiusculo:");
        for (int i = 0; i < size; i++)
        {
            if(vet[i] >= 'a' && vet[i] <= 'z'){
                printf("%c ", vet[i] - 32);
            } else if(vet[i] >= 'A' && vet[i] <= 'Z'){
                printf("%c ", vet[i]);
            } else {
                continue;
            }
        }
        printf("\n");
        
    } else {
        printf("Comando inexistente\n");
    }
    
    
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


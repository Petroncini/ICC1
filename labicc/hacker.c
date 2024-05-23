#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int soma_fatores(int n);
void entrar_dados(int *ip, int *codigo, char **conteudo, int n);
void sort(int *ip, int *codigo, char **conteudo, int n);
void swap_int(int *array, int i);
void swap_char(char **array, int i);
void print(int *codigo, char **conteudo, int n);
void free_matrix(char **mat, int size);


int main(void){
    int n;
    scanf("%d", &n);

    if(n == 0){
        printf("Sem produtos a serem cadastrados\n");
        return 0;
    }

    int *ip = malloc(n * sizeof(int));
    int *codigo = malloc(n * sizeof(int));
    char **conteudo = malloc(n * sizeof(char*));
    entrar_dados(ip, codigo, conteudo, n);
    sort(ip, codigo, conteudo, n);
    print(codigo, conteudo, n);

    free(ip);
    free(codigo);
    free_matrix(conteudo, n);
    
    

}

int soma_fatores(int n){
    int soma = 0;
    for (int i = 2; i <= n; i++){
        if(n % i == 0){
            soma += i;
            while(n %i == 0){
                n /= i;
            }
        }
    }
    
    return soma;
}

void entrar_dados(int *ip, int *codigo, char **conteudo, int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ip[i]);
        scanf("%d", &codigo[i]);
        long long int soma = soma_fatores(codigo[i]);
        conteudo[i] = malloc(soma * sizeof(char));
        scanf("%s", conteudo[i]);
    }
}

void sort(int *ip, int *codigo, char **conteudo, int n){
    int swap = 1;
    while (swap){
        swap = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if(ip[i] < ip[i + 1]){
                swap_int(ip, i);
                swap_int(codigo, i);
                swap_char(conteudo, i);
                swap = 1;
            }
        }
        
    }
}

void swap_int(int *array, int i){
    int temp = array[i];
    array[i] = array[i + 1];
    array[i + 1] = temp;
}

void swap_char(char **array, int i){
    char *temp = array[i];
    array[i] = array[i + 1];
    array[i + 1] = temp;
}

void print(int *codigo, char **conteudo, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", conteudo[i], codigo[i]);
    }
}

void free_matrix(char **mat, int size){
    for (int i = 0; i < size; i++)
    {
        free(mat[i]);
    }
    free(mat);
    
}
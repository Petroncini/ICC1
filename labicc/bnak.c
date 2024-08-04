#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char *name;
        long long int cpf;
        int age;
        float balance;
        float credit;
    } account;

int main(void){
    int n;
    scanf("%d", &n);
    getchar();

    account *clients = malloc(n * sizeof(account));

    for (int i = 0; i < n; i++)
    {
       char * string = malloc(30 * sizeof(char));
       scanf(" %[^,], %lld , %d , %f , %f", string, &clients[i].cpf, &clients[i].age, &clients[i].balance, &clients[i].credit);
       clients[i].name = malloc(strlen(string) * sizeof(char));
       strcpy(clients[i].name, string);
       free (string);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Dados da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", clients[i].name);
        printf("CPF: %011lld\n", clients[i].cpf);
        printf("Idade: %d\n", clients[i].age);
        printf("Saldo: %.2f\n", clients[i].balance);
        printf("Credito: %.2f\n\n", clients[i].credit);
    }
    printf("Pessoas endividadas:");
    
    int debt = 0;

    for (int i = 0; i < n; i++)
    {
        
        if(clients[i].balance - clients[i].credit >= 0){
            continue;
        }
        debt = 1;
        printf("\nNome: %s\n", clients[i].name);
        printf("CPF: %011lld\n", clients[i].cpf);
        printf("Divida: %.2f\n", -1*(clients[i].balance - clients[i].credit));

    }
    if(!debt){
        printf("\nNenhuma pessoa endividada encontrada.\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(clients[i].name);
    }
    free(clients);
    
}
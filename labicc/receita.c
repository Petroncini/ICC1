#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
} receita;

void registrarReceita(receita **livroDeReceitas, int *numReceitas);
void comprarIngredientes(receita *inventario);
void cozinhar(receita *inventario, receita *livroDeReceitas, int numReceitas);
void fecharCozinha(receita inventario, int numReceitas);

int main(void){
    receita *livroDeReceitas = malloc(10 * sizeof(receita));
    int numReceitas = 0;
    receita inventario;
    inventario.farinha = 0;
    inventario.ovos = 0;
    inventario.oleo = 0;
    inventario.acucar = 0;
    inventario.chocolate = 0;

    char operacao;

    while(1){

        scanf(" %c", &operacao);

        switch(operacao){
            case 'R':
                registrarReceita(&livroDeReceitas, &numReceitas);
                break;
            case 'C':
                comprarIngredientes(&inventario);
                break;
            case 'F':
                cozinhar(&inventario, livroDeReceitas, numReceitas);
                break;
            case 'S':
                fecharCozinha(inventario, numReceitas);
                free(livroDeReceitas);
                return 0;
            default:
                printf("Codigo invalido\n");
                break;
        }
    }
}

void registrarReceita(receita **livroDeReceitas, int *numReceitas){
    scanf("%s %d %d %d %d %d", 
          (*livroDeReceitas)[*numReceitas].nome, 
          &(*livroDeReceitas)[*numReceitas].farinha, 
          &(*livroDeReceitas)[*numReceitas].ovos, 
          &(*livroDeReceitas)[*numReceitas].oleo, 
          &(*livroDeReceitas)[*numReceitas].acucar, 
          &(*livroDeReceitas)[*numReceitas].chocolate);

    (*numReceitas)++;

    if((*numReceitas) % 10 == 0){
        *livroDeReceitas = realloc(*livroDeReceitas, (*numReceitas + 10) * sizeof(receita));
    }
}

void comprarIngredientes(receita *inventario){
    receita compras;
    
    scanf("%d %d %d %d %d", 
          &compras.farinha, 
          &compras.ovos, 
          &compras.oleo, 
          &compras.acucar, 
          &compras.chocolate);

    (*inventario).farinha += compras.farinha;
    (*inventario).ovos += compras.ovos;
    (*inventario).oleo += compras.oleo;
    (*inventario).acucar += compras.acucar;
    (*inventario).chocolate += compras.chocolate;
}

void cozinhar(receita *inventario, receita *livroDeReceitas, int numReceitas){
    
    int receitaIndex;
    scanf("%d", &receitaIndex);
    getchar();

    if(receitaIndex > numReceitas - 1){
        printf("Receita nao encontrada!\n");
        return;
    }

    if(livroDeReceitas[receitaIndex].farinha > (*inventario).farinha){
        printf("Farinha insuficiente\n");
        return;
    }
    if(livroDeReceitas[receitaIndex].ovos > (*inventario).ovos){
        printf("Ovos insuficientes\n");
        return;
    }
    if(livroDeReceitas[receitaIndex].oleo > (*inventario).oleo){
        printf("Oleo insuficiente\n");
        return;
    }
    if(livroDeReceitas[receitaIndex].acucar > (*inventario).acucar){
        printf("Acucar insuficiente\n");
        return;
    }
    if(livroDeReceitas[receitaIndex].chocolate > (*inventario).chocolate){
        printf("Chocolate insuficiente\n");
        return;
    }

    (*inventario).farinha -= livroDeReceitas[receitaIndex].farinha;
    (*inventario).ovos -= livroDeReceitas[receitaIndex].ovos;
    (*inventario).oleo -= livroDeReceitas[receitaIndex].oleo;
    (*inventario).acucar -= livroDeReceitas[receitaIndex].acucar;
    (*inventario).chocolate -= livroDeReceitas[receitaIndex].chocolate;

    printf("%s feita com sucesso!\n", livroDeReceitas[receitaIndex].nome);
}

void fecharCozinha(receita inventario, int numReceitas){
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", inventario.acucar);
    printf("Chocolate: %d\n", inventario.chocolate);
    printf("Farinha: %d\n", inventario.farinha);
    printf("Oleo: %d\n", inventario.oleo);
    printf("Ovos: %d\n", inventario.ovos);
    printf("Receitas cadastradas: %d\n", numReceitas);
}

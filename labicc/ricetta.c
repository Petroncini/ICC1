#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int farina;
    int uova;
    int olio;
    int zucchero;
    int cioccolato;
} ricetta;

void registrareRicetta(ricetta **librodiCucina, int *numRicette);
void acquistareIngredienti(ricetta *inventario);
void cucinare(ricetta *inventario, ricetta *libroDiCucina, int numRicette);
void chiudereCucina(ricetta inventario, int numRicette);

int main(void){
    ricetta *libroDiCucina = malloc(10 * sizeof(ricetta));
    int numRicette = 0;
    ricetta inventario;
    inventario.farina = 0;
    inventario.uova = 0;
    inventario.olio = 0;
    inventario.zucchero = 0;
    inventario.cioccolato = 0;

    char operazione;

    while(1){

        scanf(" %c", &operazione);

        switch(operazione){
            case 'R':
                registrareRicetta(&libroDiCucina, &numRicette);
                break;
            case 'C':
                acquistareIngredienti(&inventario);
                break;
            case 'F':
                cucinare(&inventario, libroDiCucina, numRicette);
                break;
            case 'S':
                chiudereCucina(inventario, numRicette);
                free(libroDiCucina);
                return 0;
            default:
                printf("Codigo invalido\n");
                break;
        }
    }
}

void registrareRicetta(ricetta **librodiCucina, int *numRicette){
    scanf("%s %d %d %d %d %d", 
          (*librodiCucina)[*numRicette].nome, 
          &(*librodiCucina)[*numRicette].farina, 
          &(*librodiCucina)[*numRicette].uova, 
          &(*librodiCucina)[*numRicette].olio, 
          &(*librodiCucina)[*numRicette].zucchero, 
          &(*librodiCucina)[*numRicette].cioccolato);

    (*numRicette)++;

    if((*numRicette) % 10 == 0){
        *librodiCucina = realloc(*librodiCucina, (*numRicette + 10) * sizeof(ricetta));
    }
}

void acquistareIngredienti(ricetta *inventario){
    ricetta acquisti;
    
    scanf("%d %d %d %d %d", 
          &acquisti.farina, 
          &acquisti.uova, 
          &acquisti.olio, 
          &acquisti.zucchero, 
          &acquisti.cioccolato);

    (*inventario).farina += acquisti.farina;
    (*inventario).uova += acquisti.uova;
    (*inventario).olio += acquisti.olio;
    (*inventario).zucchero += acquisti.zucchero;
    (*inventario).cioccolato += acquisti.cioccolato;
}

void cucinare(ricetta *inventario, ricetta *libroDiCucina, int numRicette){
    
    int ricettaIndex;
    scanf("%d", &ricettaIndex);
    getchar();

    if(ricettaIndex > numRicette - 1){
        printf("Receita nao encontrada!\n");
        return;
    }

    if(libroDiCucina[ricettaIndex].farina > (*inventario).farina){
        printf("Farinha insuficiente\n");
        return;
    }
    if(libroDiCucina[ricettaIndex].uova > (*inventario).uova){
        printf("Ovos insuficientes\n");
        return;
    }
    if(libroDiCucina[ricettaIndex].olio > (*inventario).olio){
        printf("Oleo insuficiente\n");
        return;
    }
    if(libroDiCucina[ricettaIndex].zucchero > (*inventario).zucchero){
        printf("Acucar insuficiente\n");
        return;
    }
    if(libroDiCucina[ricettaIndex].cioccolato > (*inventario).cioccolato){
        printf("Chocolate insuficiente\n");
        return;
    }

    (*inventario).farina -= libroDiCucina[ricettaIndex].farina;
    (*inventario).uova -= libroDiCucina[ricettaIndex].uova;
    (*inventario).olio -= libroDiCucina[ricettaIndex].olio;
    (*inventario).zucchero -= libroDiCucina[ricettaIndex].zucchero;
    (*inventario).cioccolato -= libroDiCucina[ricettaIndex].cioccolato;

    printf("%s feita com sucesso!\n", libroDiCucina[ricettaIndex].nome);
}

void chiudereCucina(ricetta inventario, int numRicette){
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", inventario.zucchero);
    printf("Chocolate: %d\n", inventario.cioccolato);
    printf("Farinha: %d\n", inventario.farina);
    printf("Oleo: %d\n", inventario.olio);
    printf("Ovos: %d\n", inventario.uova);
    printf("Receitas cadastradas: %d\n", numRicette);
}
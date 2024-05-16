#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int pontos_fixo[n];
    int colocacoes[n];
    int pontos[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pontos_fixo[i]);
        pontos[i] = pontos_fixo[i];
        colocacoes[i] = i;
    }
    
    int swap = 1;
    while (swap != 0)
    {
        swap = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if(pontos[j] < pontos[j + 1]){
                int temp = pontos[j];
                pontos[j] = pontos[j + 1];
                pontos[j + 1] = temp;
                swap++;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", pontos[i]);
    // }
    // printf("\n");

   
    

    for (int i = 0; i < n; i++)
    {
        int prev_ponto = -1;
        int empates = 0;
        for (int j = 0; j < n; j++)
        {  
            if(pontos[j] == prev_ponto){
                empates++;
            }
            prev_ponto = pontos[j];

            if(pontos_fixo[i] == pontos[j]){

                colocacoes[i] = j + 1 - empates;
                break;
            }
        }
        
    }
    

    // for (int i = 1; i < n; i++)
    // {
    //     printf("pontos i - 1(%d): %d, pontos i(%d): %d\n", colocacoes[i - 1], pontos[i - 1],   colocacoes[i], pontos[i]);
    //     if (pontos[i] == pontos[i - 1]){
    //         printf("EMPATE\n");
    //         empates[i] = empates[i - 1] + 1;
    //     } else {
    //         empates[i] = empates[i - 1];
    //     }
    // }
    

   

    for (int i = 0; i < n; i++)
    {
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i + 1, pontos_fixo[i], colocacoes[i]);
    }
    
    
    

}
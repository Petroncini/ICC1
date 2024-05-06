#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    if(!n){
        printf("Sem atividades registradas hoje\n");
        return 0;
    }

    float profits[n];

    float buy, sell;
    int gain, lose;

    int highest_profit = 0;
    float net = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%f %f %d %d", &buy, &sell, &gain, &lose);
        profits[i] = (sell * lose) - (buy * gain);
        

        net += profits[i];

        if(profits[i] > profits[highest_profit]){
            highest_profit = i;
        }

    }

    if(net >= 0){
        printf("lucro: %.2f\n", net);
    } else {
        printf("prejuizo: %.2f\n", net * -1);
    }
    
    printf("produto: %d lucro relativo: %.2f\n", highest_profit + 1, profits[highest_profit]);
}
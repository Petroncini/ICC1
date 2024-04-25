#include <stdio.h>

int main(void){
    int x;
    scanf("%d", &x);
    double acc = 0;

    for (int i = 0; i < 100; i++)
    {
        double exp = 1;
        for (int k = 0; k < i; k++)
        {
            exp *= x;
        }

        double fat = 1;
        for (int k = 0; k < i; k++)
        {
            fat *= i - k;
        }

        acc += exp/fat;

        //printf("exp: %lf; fat: %lf; acc: %lf\n", exp, fat, acc);
        
        
    }
    
    printf("%lf\n",acc);

}
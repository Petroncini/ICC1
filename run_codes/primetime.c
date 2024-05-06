#include <stdio.h>

int main(void){
    int primes[1000000];
    int prime_count = 1;
    primes[0] = 2;

    for (int i = 2; i < 1500; i++)
    {
        int prime = 1;

        for (int j = 0; j < prime_count; j++)
        {
            if(i%primes[j]==0){
                prime = 0;
            }
        }

        if(prime){
            primes[prime_count++] = i;
        }
    }
    
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int n;
        scanf("%d", &n);

        int prime = 1;

        for (int j = 0; j < prime_count; j++)
        {
            if(primes[j] == n){
                break;
            }
            if(n%primes[j]==0){
                prime = 0;
                break;
            }
        }

        if(prime){
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }

    }
    
}
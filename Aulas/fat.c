#include <stdio.h>

long long int fat(long long int n);

int main(void){
    for (int i = 0; i < 80; i++)
    {
         printf("%d!= %lld\n", i, fat(i) * 4);
    }
}

long long int fat(long long int n){
    if(n == 0){
        return 1;
    }
    return n * fat(n - 1);
}
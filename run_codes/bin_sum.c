#include <stdio.h>

int power(int base, int exp);

int main(void){
    int n, m, a = 0, b = 0, in = 0;

    scanf("%i %i", &n, &m);

    for (int i = n - 1; i >= 0; i--)
    {
        scanf("%i", &in);
        a += in * power(2, i);
    }

    for (int i = m - 1; i >= 0; i--)
    {
        scanf("%i", &in);
        b += in * power(2, i);
    }

    printf("%i\n", a + b);
    
}

int power(int base, int exp) {
    if(exp == 0){
        return 1;
    } else {
        return base * power(base, exp - 1);
    }
}
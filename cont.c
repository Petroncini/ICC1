#include <stdio.h>

int power(int base, int exp);

int main(void){
    int n, m, a = 0, b = 0, in = 0;

    scanf("%i %i", &n, &m);

    for (int i = n - 1; i >= 0; i--)
    {
        scanf("%i", &in);
        int pow = 1;
        for (int k = 0; k < i; k++)
        {
               pow *= 2;
        }
        a += in * pow;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        scanf("%i", &in);
        int pow = 1;
        for (int k = 0; k < i; k++)
        {
               pow *= 2;
        }
        b += in * pow;
    }

    printf("%i\n", a + b);
    
}


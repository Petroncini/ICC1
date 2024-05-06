#include <stdio.h>



int main(void){
    int n, m, a = 0, b = 0, in = 0;

    scanf("%i %i", &n, &m);

    for (int i = n - 1; i >= 0; i--)
    {
        scanf("%i", &in);
        //a += in * power(2, i);
        if(i == 0){
            a += in;
        } else {
            a += in * (2<<(i-1));
        }
        
    }

    for (int i = m - 1; i >= 0; i--)
    {
        scanf("%i", &in);
        //b += in * power(2, i);
        if(i == 0){
            b += in;
        } else {
            b += in * (2<<(i-1));
        }
    }

    printf("%i\n", a + b);
    
}


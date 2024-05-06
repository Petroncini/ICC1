#include <stdio.h>

int power(int a, int b);

int main(void){
    int n, m, a[128], b[128];
    int *pa, *pb;
    pa = a;
    pb = b;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", pa++);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", pb++);
    }

    pa--;
    pb--;

    int x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        //printf("%dˆ2: %d\n", *pa--, power(2, i));
        x += (*pa--) * power(2, i);
        
    }

    for (int i = 0; i < m; i++)
    {
        y += *pb-- * power(2, i);
    }

    printf("%d", x + y);
    
    
}

int power(int a, int b){
    if (b == 0){
        return 1;
    }

    return a * power(a, b - 1);
}
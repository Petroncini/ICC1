#include <stdio.h>

int main(void){
    int n;
    int vec[100000];
    int *p;
    p = vec;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", p++);
    }

    p--;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *p--);
    }
    
    printf("\n");
}
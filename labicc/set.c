#include <stdio.h>

int main(void){
    int n, m;
    scanf("%d", &n);
    int a[100000], b[100000];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", b + i);
    }


    int with[n + m];
    int without[n + m];
    int with_count = 0;
    int without_count = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < m; j++)
        {
            if(a[i] == b[j]){
                with[with_count++] = a[i];
                found = 1;
                break;
            }
        }

        if(!found){
            without[without_count++] = a[i];
        }
    }
    
    printf("intersecao: ");

    if(with_count == 0){
        printf("vazio");
    } else {
        for (int i = 0; i < with_count; i++)
        {
            printf("%d ", with[i]);
        }
    }

    printf("\na - b: ");

    if(without_count == 0){
        printf("vazio");
    } else {
        for (int i = 0; i < without_count; i++)
        {
            printf("%d ", without[i]);
        }
    }

    printf("\n");
    
}
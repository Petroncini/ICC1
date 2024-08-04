#include <stdio.h>
#include <stdlib.h>

void recPrint(int m, int *str);

int main(void){
    int m;
    scanf("%d", &m);
    int *str = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        str[i] = 97;
    }
    
    recPrint(m, str);
}

void recPrint(int m, int *str){
    for (int i = m - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    str[0]++;
    for (int i = 0; i < m; i++)
    {
        if(str[i] > 122){
            str[i] = 97;
            str[i + 1]++;
            if(i == m - 1){
                return;
            }
        }
    }
    recPrint(m, str);
}
#include <stdio.h>

void what(int *a, int *b, int *c);

int main(void){
    int a, b, c;
    what(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
}

void what(int *a, int *b, int *c){
    scanf("%d %d %d", a, b, c);
    int *arr[] = {a, b, c};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if(*arr[j + 1] < *arr[j]){
                int temp = *arr[j];
                *arr[j] = *arr[j + 1];
                *arr[j + 1] = temp;
            }
        }
    }
}
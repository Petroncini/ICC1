#include <stdio.h>

int recAdd(int a, int b);

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", recAdd(a, b));

}

int recAdd(int a, int b){
    if(b == 0){
        return a;
    }

    return recAdd(a + 1, b - 1);
}
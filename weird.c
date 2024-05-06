#include <stdio.h>

int main(void){
    int n;
    char vec[10000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", vec + i);
    }
    char *left, *right;
    left = right = vec;

    if(n%2==0){
        left += (n/2) - 1;
        right += (n/2);
    } else {
        left += (n/2);
        right += (n/2) + 1;
    }
    
    

    if(n%2 == 1){
        printf("%c", *left);
        left--;
    }

    for (int i = 0; i < n/2; i++)
    {
        printf("%c", *left--);
        printf("%c", *right++);
    }
    
    printf("\n");
    
   
    
    
}
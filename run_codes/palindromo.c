#include <stdio.h>


int main(void){
    int q;
    char in;
    int pal = 0;

    scanf("%d ", &q);

    do{
        scanf("%c", &in);
        if(in >= 'a') pal = pal^(1 << (in - 'a'));
        
    } while(in != '\n');
    
    if((pal & (pal - 1)) == 0){
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
}

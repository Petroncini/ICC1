#include <stdio.h>


int main(void){
    int n;
    char in;
    int pal = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &in);
        //pal = pal^power(2, in - 'a');
        if(in - 'a' == 0){
            pal = pal^1;
        } else {
            pal = pal^(2 << (in-'a' - 1));
        }
    }

    if(pal == 0){
        printf("Sim\n");
    } else {
        for (int i = 0; i < n; i++)
        {
            int power;
            if(i == 0){
                power = 1;
            } else {
                power = 2 << (i - 1);
            }
            if(pal == power){
                printf("Sim\n");
                return 0;
            }
        }
        printf("Nao\n");
        
    }

}

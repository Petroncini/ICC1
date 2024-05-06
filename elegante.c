#include <stdio.h>

int main(void){
    char vec[100000];
    char *p;
    int n = -1;
    p = vec;

    do {
        scanf("%c", p++);
        n++;
    } while(*(p - 1) != '\n');


    printf("%i\n", n/2);

    p = vec;
    p += n/2;

    for (int i = 0; i < n; i++)
    {
        printf("%c", *p);
        if(i%2==0){
            p -= i + 1;
        } else {
            p += i + 1;
        }
    }
    

    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("Error\n");
        return 1;
    }

    char c;
    
    do{
        fscanf(fp, "%c", &c);
        printf("%c", c);
    } while(c != '$');



    fclose(fp);
    return 0;
}
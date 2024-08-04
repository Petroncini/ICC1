#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int fileIndex = 0;
    char c = ' ';
    while(c != EOF){
        for (int i = 0; i < 20;){
        c = fgetc(fp);

        if(c == '\n'){
            i++;
        }

        if(c == EOF){
            break;
        }

        printf("%c", c);
        }
        getchar();
    }
}
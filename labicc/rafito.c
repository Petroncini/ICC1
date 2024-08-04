#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char chave[20];
    char arquivo[30];

    scanf("%s %s", chave, arquivo);
    int chaveLen = strlen(chave);

    FILE *fp;
    fp = fopen(arquivo, "r");

    int size = 0;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    char *content = malloc(size + 1);

    fread(content, size, 1, fp);
    content[size] = '\0';
    //printf("%s\n", content);

    char *trava = strstr(content, chave);

    char *out = malloc(size + 1 - strlen(chave));
    if(*(trava + chaveLen) == ' '){
        chaveLen++;
    }
    int k = 0;
    
    char *p = content;
    while(*p != '\0'){
        if(p == trava){
            p += chaveLen;
            continue;
        }
        out[k++] = (*p++);
    }
    

    printf("%s\n", out);
    free(content);
    free(out);
}
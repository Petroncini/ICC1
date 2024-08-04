#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char filename[15], word[20];
    word[0] = ' ';

    scanf("%s", filename);
    scanf("%s", word + 1);

    int wordLen = strlen(word);

    for (int i = 0; i < wordLen; i++)
    {
        if(word[i] < 'a'){
            word[i] += 32;
        }
    }

    FILE *fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *content = malloc(size + 2);
    fread(content + 1, size + 2, 1, fp);
    content[0] = ' ';

    for (int i = 0; i < size; i++)
    {
        if(content[i] < 'a'){
            content[i] += 32;
        }
    }

    int r = 0;

    char *p = content;

    while((p = strstr(p, word)) != NULL){
        r++;
        p += wordLen;
    }
    
    printf("quantidade: %d\n", r);
    free(content);
    fclose(fp);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char filename[15];
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "rb");

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *content = malloc(size);

    for (int i = 0; i < size; i++)
    {
        fread(&content[i], sizeof(char), 1, fp);
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%c", content[i]);
    }
    printf("\n");

    fclose(fp);
    free(content);
}
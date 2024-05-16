#include <stdio.h>


int main(void){
    int q;
    char in = 'a';
    

    scanf("%d ", &q);

    for (int i = 0; i < q; i++)
    {
        int pal = 0;
        char word[30];
        char *wp;
        wp = word;
        int word_len = -1;

        scanf("%s", word);
        do{
            in = *wp++;
            if(in >= 'a') {
                pal = pal^(1 << (in - 'a'));
                word_len++;
            }

        } while(in != '\0');

        wp = word;

        printf("%s ", word);
        
        
        if((pal & (pal - 1)) == 0){
            printf("eh um palindromo\n");
        } else {
            printf("nao eh um palindromo\n");
        }
    }
    

   
}

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int operacao;
    //int produto;
    int estoque = 0;
    bool finished = false;

    while(!finished) {
        scanf("%d", &operacao);

        if (operacao == 1) {
            scanf("%*d\n");
        }

        switch(operacao) {
            case 1:
                estoque++;
                break;

            case 2:
                printf("%d\n", estoque);
                break;
            case 3:
                finished = true;

        }
    }
    return 0;
}
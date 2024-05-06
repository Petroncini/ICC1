#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int op1 = atoi(argv[1]);
    int op = argv[2][0];
    int op2 = atoi(argv[3]);

    switch (op){
        case '+': 
            printf("%d\n", op1 + op2);
            break;
        case '-': 
            printf("%d\n", op1 - op2);
            break;
        case 'x': 
            printf("%d\n", op1 * op2);
            break;
        case '/': 
            printf("%d\n", op1 / op2);
            break;
    }

}
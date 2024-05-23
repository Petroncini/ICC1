#include <stdio.h>
#include <stdlib.h>

char ** build_board(int n, int m);
void set_board(char **board, int n, int m);
int available(char **board, int i, int j);
void find_spots(char **board, int n, int m);
void print_board(char **board, int n, int m);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    char **board = build_board(n + 2, m + 2); // é feita um tabuleiro com uma borda de espaços vazios para facilitar o cálculo do número de vizinhos
    set_board(board, n, m);
    find_spots(board, n, m);
    print_board(board, n, m);
}

char **build_board(int n, int m){ //aloca a memória para a matrix que armazena os locais das peças no tabuleiro
    char **mat = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        mat[i] = malloc(sizeof(char) * m);
    }
    return mat;
}

void set_board(char **board, int n, int m){ // recebe o input do usuário para preencher o tabuleiro
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            if((i == 0) || ( j == 0) || (i == n + 1) || (j == m + 1)){
                board[i][j] = '.';
            } else {
                scanf(" %c", &board[i][j]);
            }
        } 
    }
}

int available(char **board, int i, int j){  //retorna se um dado espaço no tabuleiro está disponivel contando os seus vizinhos
    if(board[i][j] != '.'){
        return 0;
    }
    int count = 0;
    if(board[i - 1][j] == 'X'){count++;}
    if(board[i + 1][j] == 'X'){count++;}
    if(board[i][j - 1] == 'X'){count++;}
    if(board[i][j + 1] == 'X'){count++;}

    if(count %2 == 0){
        return 1;
    } else {
        return 0;
    }
}

void find_spots(char **board, int n, int m){ // preenche of espaços disponíveis com um asterisco na matriz do tabuleiro
    for (int i = 1; i < n + 1; i++)
    {
       for (int j = 1; j < m + 1; j++)
       {
            if(available(board, i, j)){
                board[i][j] = '*';
            }
       }
    }
}

void print_board(char **board, int n, int m){ // imprime o estado atual da matriz do tabuleiro
    for (int i = 1; i < n + 1; i++)
    {
       for (int j = 1; j < m + 1; j++)
       {
            printf("%c", board[i][j]);
       }
       printf("\n");
    }
}
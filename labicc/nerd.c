#include <stdio.h>

void be_seated(int n, int m, int rows[20], int cols[20], char bancada[20][20]);
void arrange(int n, int m, int rows[20], int cols[20], char bancada[20][20], int *disp);
void printout(int n, int m, char bancada[20][20], int disp);

int main(void){
    int n, m;
    int rows[20];
    int cols[20];
    char bancada[20][20];
    int disp = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        rows[i] = 1;
    }
    
    for (int i = 0; i < m; i++)
    {
        cols[i] = 1;
    }

    

    be_seated(n, m, rows, cols, bancada);
    arrange(n, m, rows, cols, bancada, &disp);
    printout(n, m, bancada, disp);

    
}

void be_seated(int n, int m, int rows[20], int cols[20], char bancada[20][20]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char assento;
            
            scanf(" %c", &assento);
            bancada[i][j] = assento;

            if(assento == 'c'){
                //printf("cosplayer on row %d and col %d\n", i, j);
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }
}

void arrange(int n, int m, int rows[20], int cols[20], char bancada[20][20], int *disp){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if((rows[i] && cols[j]) && bancada[i][j] == 'v'){
                bancada[i][j] = 'o';
                *disp += 1;
            } else {
                bancada[i][j] = 'x';
            }
        }
    }
}

void printout(int n, int m, char bancada[20][20], int disp){
    if (disp == 0){
        printf("Eh um dia triste para os mono Yasuo\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c ", bancada[i][j]);
        }
        printf("\n");
    }
}


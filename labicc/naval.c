#include <stdio.h>

void deploy(int n, char sea[26][26]);
void bombs_away(int n, char sea[26][26], int shells);
void radar_ping(int n, char sea[26][26]);

int main(void){
    char sea[26][26];

    int n;
    scanf("%d", &n);

    deploy(n, sea);

    int shells;
    scanf("%d", &shells);

    bombs_away(n, sea, shells);

    radar_ping(n, sea);


}

void deploy(int n, char sea[26][26]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &sea[i][j]);
        }
    }
}

void bombs_away(int n, char sea[26][26], int shells){
    for (int i = 0; i < shells; i++)
    {

       char x;
       int y;

       scanf(" %c%d", &x, &y);
       
       x -= 'A';
       y -= 1;

       if(sea[x][y] == 'O' || sea[x][y] == 'X'){
            printf("erro!\n");

       } else{
            sea[x][y] = 'X';
            printf("acerto!\n");
       }
    }
}

void radar_ping(int n, char sea[26][26]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", sea[i][j]);
        }
        printf("\n");
    }
}
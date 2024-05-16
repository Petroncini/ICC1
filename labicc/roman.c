#include <stdio.h>

void roman(int rom, int u, int d, int c, int m, char *uni, char *dez, char *cen, char *mil);

int main(void){

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int rom;
        scanf("%d", &rom);
        int u = 0, d = 0, c=0, m=0;

        char uni[100];
        char dez[100];
        char cen[100];
        char mil[100];

        roman(rom, u, d, c, m, uni, dez, cen, mil);
    }

}

void roman(int rom, int u, int d, int c, int m, char *uni, char *dez, char *cen, char *mil){
    for (int i = 0; i < rom/1000; i++)
    {
        mil[i] = 'M';
        m++;
    }

    rom %= 1000;
    int cent = rom/100;
    //printf("cent: %d\n", cent);

    if(cent <= 3){
        for (int i = 0; i < cent; i++)
        {
            cen[i] = 'C';
            c++;
        }

    } else if(cent == 4){
        cen[0] = 'C';
        cen[1] = 'D';
        c += 2;

    } else if(cent < 9){
        cen[0] = 'D';
        c++;
        for (int i = 0; i < cent - 5; i++)
        {
            cen[i + 1] = 'C';
            c++;
        }

    } else {
        cen[0] = 'C';
        cen[1] = 'M';
        c += 2;
    }

    rom %= 100;
    int deze = rom/10;
    //printf("deze: %d\n", deze);

    if(deze <= 3){
        for (int i = 0; i < deze; i++)
        {
            dez[i] = 'X';
            d++;
        }

    } else if(deze == 4){
        dez[0] = 'X';
        dez[1] = 'L';
        d += 2;

    } else if(deze < 9){
        dez[0] = 'L';
        d++;
        for (int i = 0; i < deze - 5; i++)
        {
            dez[i + 1] = 'X';
            d++;
        }

    } else {
        dez[0] = 'X';
        dez[1] = 'C';
        d += 2;
    }

    

    rom %= 10;
    int unid = rom;
    //printf("unid: %d\n", unid);

    if(unid <= 3){
        for (int i = 0; i < unid; i++)
        {
            uni[i] = 'I';
            u++;
        }

    } else if(unid == 4){
        uni[0] = 'I';
        uni[1] = 'V';
        u += 2;

    } else if(unid < 9){
        uni[0] = 'V';
        u++;
        for (int i = 0; i < unid - 5; i++)
        {
            uni[i + 1] = 'I';
            u++;
        }

    } else {
        uni[0] = 'I';
        uni[1] = 'X';
        u += 2;
    }
    
    for (int i = 0; i < m; i++)
    {
        printf("%c", mil[i]);
    }

    for (int i = 0; i < c; i++)
    {
        printf("%c", cen[i]);
    }

    for (int i = 0; i < d; i++)
    {
        printf("%c", dez[i]);
    }

    for (int i = 0; i < u; i++)
    {
        printf("%c", uni[i]);
    }
    
    printf("\n");
}
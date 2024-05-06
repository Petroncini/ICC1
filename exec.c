#include <stdio.h>


int main (void){
     int x;
     scanf("%i", &x);
     double acc = x; // acumulador
     int add = 0; // somar ou subtrair / verdadeiro ou falso;

     for(int i = 2, j = 3; i <= 38; i += 2, j += 2){
          double exp = 1;
          for (int k = 0; k < i; k++)
          {
               exp *= x;
          }

          double fat = 1;

          for (int k = 0; k < j; k++)
          {
               fat *= j - k;
          }

          if(add){
               //printf("+%iˆ%i/%i! = +%lf/%lf\n", x, i, j, exp, fat);
               add = 0;
               acc += exp/fat;
          } else {
               //`printf("-%iˆ%i/%i! = -%lf/%lf\n", x, i, j, exp, fat);
               add = 1;
               acc -= exp/fat;
          }
     }
     printf(" = %lf", acc);
}
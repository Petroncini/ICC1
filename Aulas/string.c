#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
   char str[1000];
   fgets(str, 1000, stdin);
   int len = 0;

   for (int i = 0; i < 1000; i++)
   {
        if(str[i] == '\0'){
            break;
        }
        len++;
   }
   printf("strlen: %d\n", len);
}
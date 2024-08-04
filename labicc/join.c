#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearString(char *str, int strLen);
void printA(char *param, char* A, int Alen);
void printB(char *param, char* B, int Blen);

int main(void){
    char A[130];
    char B[130];

    fgets(A, 130, stdin);
    fgets(B, 130, stdin);

    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';

    int lenA = strlen(A);
    int lenB = strlen(B);

    char anchor[20];
    fgets(anchor, 20, stdin);
    anchor[strcspn(anchor, "\n")] = '\0';
    int lenAnchor = strlen(anchor);

    char *endA = strstr(A, anchor);

    if (endA == NULL) {
        endA = A + lenA;
    }

    char *startB = strstr(B, anchor);
    
    char *startA = A;
    if(startA < endA){
        while (startA != endA - 1) {
            printf("%c", *(startA++));
        }
    } else {
        while (startA != endA) {
            printf("%c", *(startA++));
        }
        startB++;
    }
    

    if (startB != NULL) {
        startB += lenAnchor ;
        while (*startB != '\0') {
            printf("%c", *(startB++));
        }
        printf("\n");
    }
    return 0;
}

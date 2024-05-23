#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void enter_vector(int *array, int size);
void print_vector(int *array, int size);
int contains(int *array, int size, int n);
int *intersect (int *A, int n, int *B, int m, int *intersect_size);
int *union_ (int *A, int n, int *B, int m, int *intersect, int *intersect_size, int *union_size);
int *unionminteresct( int *intersect, int *intersect_size,int *union_, int *union_size, int *unionmintersect_size);
void sort_vector(int *array, int size);

int main(void){
    int n, m;
    int intersect_size = 0;
    int union_size = 0;
    int unionmintersect_size = 0;

    scanf("%d", &n);
    int *A = malloc(n * sizeof(int));
    enter_vector(A, n);
    sort_vector(A, n);


    scanf("%d", &m);
    int *B = malloc(m * sizeof(int));
    enter_vector(B, m);
    sort_vector(B, m);

    printf("conjunto A: ");
    print_vector(A, n);

    printf("conjunto B: ");
    print_vector(B, m);

    int *AiB = intersect(A, n, B, m, &intersect_size);
    sort_vector(AiB, intersect_size);

    int *AuB = union_(A, n, B, m, AiB, &intersect_size, &union_size);
    sort_vector(AuB, union_size);

    printf("A uniao B: ");

    print_vector(AuB, union_size);
    

    int *AuBmAiB = unionminteresct(AiB, &intersect_size, AuB, &union_size, &unionmintersect_size);
    sort_vector(AuBmAiB, unionmintersect_size);

    printf("(A uniao B) - (A interseccao B): ");

    print_vector(AuBmAiB, unionmintersect_size);
    
    free(A);
    free(B);
    free(AuB);
    free(AiB);
    free(AuBmAiB);
}

void enter_vector(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_vector(int *array, int size){
    if(size == 0){
        printf("vazio\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int contains(int *array, int size, int n){
    int in = 0;
    for (int i = 0; i < size; i++)
    {
        if(array[i] == n){
            in = 1;
        }
    }
    return in;
}

int *intersect (int *A, int n, int *B, int m, int *intersect_size){
    int *U = malloc(0);
    for (int i = 0; i < n; i++)
    {
        if(contains(B, m, A[i])){
            U = realloc(U, sizeof(int) * (++(*intersect_size)));
            U[*intersect_size - 1] = A[i];
        }
    }
    return U;
}

int *union_ (int *A, int n, int *B, int m, int *intersect, int *intersect_size, int *union_size){
    int *U = malloc(0);

    for (int i = 0; i < n; i++)
    {
        U = realloc(U, sizeof(int) * (++(*union_size)));
        U[*union_size - 1] = A[i];
    }

    for (int i = 0; i < m; i++)
    {
        if(!contains(intersect, *intersect_size, B[i])){
            U = realloc(U, sizeof(int) * (++(*union_size)));
            U[*union_size - 1] = B[i];
        }
    }
    

    return U;
}

int *unionminteresct( int *intersect, int *intersect_size,int *union_, int *union_size, int *unionmintersect_size){
    int *U = malloc(0);
    for (int i = 0; i < *union_size; i++)
    {
        if(!contains(intersect, *intersect_size, union_[i])){
            U = realloc(U, sizeof(int) * (++(*unionmintersect_size)));
            U[*unionmintersect_size - 1] = union_[i];
        }
    }
    return U;
}

void sort_vector(int *array, int size){
    int swap = 1;
    while (swap){
        swap = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if(array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = 1;
            }
        }
    }
}
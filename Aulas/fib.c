#include <stdio.h>
#include <time.h>

int fib(int n);

int main(void){

    clock_t start, end;
    double cpu_time_used;

    for (int i = 1; i < 100; i++)
    {
        start = clock();
        int fibNum = fib(i);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d :: %lf\n", fibNum, cpu_time_used);
    }
}

int fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

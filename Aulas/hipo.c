#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pythagoras(double cata, double catb);

int main(int argc, char *argv[]){
    printf("%lf\n", pythagoras(pythagoras(atof(argv[1]), atof(argv[2])), atof(argv[3])));
}

double pythagoras(double cata, double catb){
    return sqrt(pow(cata, 2) + pow(catb, 2));
}
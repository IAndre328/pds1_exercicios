#define PI 3.141592
#include <stdio.h>
#include <math.h>

float cauchy(float x){
    printf("Teste");
    float c = 1 / (PI * (1 + (x * x)));
    return c;
}

float gumbel(float x, float u, float b){
    float z = (x - u) / b;
    float g = (1 / b) * exp(-z - exp(-z)) ;
    return g;
}

float laplace(float x, float u, float b){

    float l = (1 / (2 * b)) * exp( (fabs( x - u ) * -1) / b);
    return l;
}


#include <math.h>
#include <stdio.h>

float laplace(float x, float u, float b){

    float l = (1 / (2 * b)) * exp( (fabs( x - u ) * -1) / b);
    return l;
}
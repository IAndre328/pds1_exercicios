#include <stdio.h>
#include "minhas_funcoes.h"



void soma1(int* ptr){
    *ptr = *ptr +1;

}

void troca(float* end_valor1, float* end_valor2){
    
    float temp = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = temp;
}


int ddd(long long number){
    int d = number / 1000000000;
    return d;
}
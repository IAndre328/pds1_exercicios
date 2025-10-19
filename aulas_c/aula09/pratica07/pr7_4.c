#include <stdio.h>

float produtoEscalar(int N, float A[], float B[]){
    
    float soma = 0;
    
    for (int i = 0; i < N; i++){
        soma += A[i] * B[i];
    }
    
    return soma;
    
}


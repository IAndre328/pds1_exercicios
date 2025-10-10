#include <stdio.h>

float calculamedia(int tamanho, float* vetor) {
    // escreva sua solução aqui
    // voce nao precisa capturar os dados do usuario com scanf nem printar a matriz
    float media = 0.0;
    // printf("Tamanho: %d\n", tamanho);
    
    
    for (int i = 0; i < tamanho; i++){
        // printf("Termo atual %f", vetor[i]);
        media += (vetor[i] / tamanho);    
        // printf("media atual %f\n", media);
    }
    
    return media;
}
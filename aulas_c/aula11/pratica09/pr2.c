#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeArray(int** arr, int qtdLinhas){
    
    for (int i = 0; i < qtdLinhas; i++) {
        free(arr[i]);
    }
    free(arr);
    
}

int readNumberArray(int*** arr, int* qtdLinhas, FILE* arq){

    int inicio = 0;
    int fim = 0;
    int intervalo = 0;
    
    fscanf(arq, "%d", &inicio);
    fscanf(arq, "%d", &fim);
    fscanf(arq, "%d", &intervalo);
    
    *qtdLinhas = 1 + (fim - inicio) / intervalo;
    
    *arr = (int**)realloc(*arr, *qtdLinhas * sizeof(int*));

    
    for (int i = 0; i < *qtdLinhas; i++){
        
        (*arr)[i] = (int*)malloc(sizeof(int) * 3);
        
        int atual = inicio + (i * intervalo);
        
        (*arr)[i][0] = atual;
        (*arr)[i][1] = atual * (9.0/5.0) + 32 + 0.5;
        (*arr)[i][2] = atual + 273;
        
    }
    
  
    return 0;
}


void printTemps(int** arr, int qtdLinhas){

    for(int i = 0; i < qtdLinhas; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
        

}

int main(){

    FILE* arq;
    arq = fopen("case.txt", "r");
    
    int** temps = NULL;
    int qtdLinhas = 0;
    

    if (arq == NULL){
        perror("Nao foi possivel abrir o arquivo");
        return 1;
    }
    
    
    readNumberArray(&temps, &qtdLinhas, arq);
    printTemps(temps, qtdLinhas);
    freeArray(temps, qtdLinhas);
    
    return 0;
}

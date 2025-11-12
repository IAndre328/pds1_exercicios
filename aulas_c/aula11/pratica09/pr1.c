#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_LINHA 100 

int returnIndexMaiorString(char** arr, int qtdLinhas){

    int maxIndex = 0;

    for (int i = 1; i < qtdLinhas; i++){

        if (strlen(arr[i]) > strlen(arr[maxIndex]))
            maxIndex = i;

    }
    
    return maxIndex;
}

void freeArray(char** arr, int qtdLinhas){
    
    for (int i = 0; i < qtdLinhas; i++) {
        free(arr[i]);
    }
    free(arr);
    
}

int main(){
    
    FILE *file;
    file = fopen("texto.txt", "r");
    
    if (file == NULL){
        printf("Não consegui abrir o arquivo");
        return 1;
    }
    
    int qtdLinhas = 0;
    char buffer[TAM_MAX_LINHA];
    char** linhas = NULL;

    while (fgets(buffer, TAM_MAX_LINHA, file) != NULL){

        linhas = realloc(linhas, (qtdLinhas + 1) * sizeof(char *));

        linhas[qtdLinhas] = strdup(buffer);

        qtdLinhas++;
    }
    
    int maiorLinha = returnIndexMaiorString(linhas, qtdLinhas);
    printf("%s%d", linhas[maiorLinha], (int)strlen(linhas[maiorLinha]));

    freeArray(linhas, qtdLinhas);
    fclose(file);
    return 0;
}

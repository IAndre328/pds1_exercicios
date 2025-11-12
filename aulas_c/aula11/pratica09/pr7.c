#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MAX_LINHA 101

void printVetorString(char** vetor, int qtdLinhas){
    
    for(int i = 0; i < qtdLinhas; i++)
        printf("%s\n", vetor[i]);
    
}

int partVetorString(char*** vetorLinhas, char* part,int* qtdLinhasVetorLinhas){
    
        char** tempVetor = realloc(*vetorLinhas, (*qtdLinhasVetorLinhas + 1) * sizeof(char*));
        
        if (tempVetor == NULL){
            perror("Não foi possível alocar a memória");
            return 1;
        }
        
        *vetorLinhas = tempVetor;

        (*vetorLinhas)[*qtdLinhasVetorLinhas] = strdup(part);
        
        (*qtdLinhasVetorLinhas)++;
        
        return 0;
}
    


int readVetorString(char*** vetorLinhas, int* qtdLinhasVetorLinhas, FILE* arq){
    
    char buffer[TAM_MAX_LINHA];
    char bufferPart[TAM_MAX_LINHA];
    
    while(fgets(buffer, TAM_MAX_LINHA, arq) != NULL){
        
        buffer[strcspn(buffer, "\n")] = 0;


        char delimitador[] = " ";
        
        strcpy(bufferPart, buffer);
        

        char* part = strtok(bufferPart, delimitador);
        
        while(part != NULL){
            
            //printf("toktok %s\n", part);
            
            int pvs = partVetorString(vetorLinhas, part, qtdLinhasVetorLinhas);
            if (pvs == 1) return 1;
   
            part = strtok(NULL, delimitador);
            
        }
        

        
    } 
        
    
    return 0;
}

int main(){
    
    FILE* arq;
    arq = fopen("texto.txt", "r");
    
    if (arq == NULL){
        perror("Não foi possível abrir o arquivo");
        return 1;
    }
    
    char** vetorLinhas = NULL;
    int qtdLinhasVetorLinhas = 0;
    
    int rvs = readVetorString(&vetorLinhas, &qtdLinhasVetorLinhas, arq);
    if (rvs == 1) return 1; // Em caso de algum erro
    
    // A leitura está ok
    
    int tamanhoPalavra = 0;
    scanf("%d", &tamanhoPalavra);
    
    for (int i = 0; i < qtdLinhasVetorLinhas; i++){
        
        if (strlen(vetorLinhas[i]) >= tamanhoPalavra) printf("%s\n", vetorLinhas[i]);
        
    }

    
    
    
    return 0;

}
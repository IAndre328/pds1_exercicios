#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readNumbersArray(int** arr, int* qtdLihas, FILE* file){
    char buffer[10];

    while (fgets(buffer, 10, file) != NULL){

        buffer[strcspn(buffer, "\n")] = 0;

        int tempInt = atoi(buffer);

        int* tempArr = (int*)realloc(*arr, ((*qtdLihas + 1) * sizeof(int)));

        if (tempArr == NULL){

            printf("Erro ao alocar memoria para o vetor.");
            free(*arr);
            return 1;
        }
        
        *arr = tempArr;
        (*arr)[*qtdLihas] = tempInt;

        //printf("valor %d\n", arr[*qtdLihas]);
        (*qtdLihas)++;
    }
    

    return 0;
}

int returnSomaTodosOsNumeros(int* arr, int qtdLinhas){

    int temp = 0;
    
    for (int i = 0; i < qtdLinhas; i++) 
        temp += arr[i];
    
    return temp;
}

int returnMaiorTodosOsNumeros(int* arr, int qtdLinhas){

    int maiorIndex = 0;

    for (int i = 1; i < qtdLinhas; i++)
        if (arr[i] > arr[maiorIndex]) maiorIndex = i;
    
    return arr[maiorIndex];

}

int returnMenorTodosOsNumeros(int* arr, int qtdLinhas){

    int menorIndex = 0;

    for (int i = 1; i < qtdLinhas; i++)
        if (arr[i] < arr[menorIndex]) menorIndex = i;
    
    return arr[menorIndex];

}

float returnMediaTodosOsPares(int* arr, int qtdLinhas){

    int qtdNumPares = 0;
    int someNumPares = 0;


    for (int i = 0; i < qtdLinhas; i++)
        if (arr[i] % 2 == 0){
            someNumPares += arr[i];
            qtdNumPares++;
        }
    
    if (qtdNumPares == 0) return 0;
        else return (float)someNumPares / qtdNumPares;
    
    
}

int returnQtdNumerosPrimos(int* arr, int qtdLinhas){

    int qtdPrimos = 0;
    

    for (int i = 0; i < qtdLinhas; i++){
        int done = 0;

        for (int j = 2; (j < arr[i] && done != 1); j++){
            done |= (arr[i] % j == 0);
        }
        
        qtdPrimos += done;
        
    }
        
    return qtdPrimos;

}

int main(){

    FILE* file = fopen("case.txt", "r");

    int* vetorNumeros = NULL;
    int qtdLinhas = 0;

    int rna = readNumbersArray(&vetorNumeros, &qtdLinhas, file);
    if (rna == 1) return 1;


    int rstn = returnSomaTodosOsNumeros(vetorNumeros, qtdLinhas);
    int rman = returnMaiorTodosOsNumeros(vetorNumeros, qtdLinhas);
    int rmen = returnMenorTodosOsNumeros(vetorNumeros, qtdLinhas);
    float rmed = returnMediaTodosOsPares(vetorNumeros, qtdLinhas);
    int rqtp = returnQtdNumerosPrimos(vetorNumeros, qtdLinhas);

    printf("A soma é: %d\n", rstn);
    printf("O maior número é: %d\n", rman);
    printf("O menor número é: %d\n", rmen);
    printf("A média dos pares é %.2f\n", rmed);
    printf("O número de primos é: %d\n", rqtp);

    free(vetorNumeros);
    fclose(file);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readNumbersArray(int* arr, int qtdLinhas, FILE* file){

    for (int i = 0; i < qtdLinhas; i++){

        int temp = 0;

        if (fscanf(file, "%d", &temp) != 1){

            printf("Erro ao associar o elemento %d ao conjunto", (i + 1));
            return 1;
        }

        //printf("valor %d\n", temp);
        arr[i] = (int)temp;
        
    }
    

    return 0;
}


int MDCDoisNumeros(int n1, int n2){

    while (n2 != 0){
        
        int r = n1 % n2;
        n1 = n2;
        n2 = r;

    }
    
    return n1;
}

int main(){

    FILE* file;

    file = fopen("case.txt", "r");

    int qtdLinhas = 4;
    int vetorNumeros[qtdLinhas];

    int rna = readNumbersArray(vetorNumeros, qtdLinhas, file);
    if (rna == 1) return 1;
    
    int mdc1e2 = MDCDoisNumeros(vetorNumeros[0], vetorNumeros[1]);
    int mdc3e4 = MDCDoisNumeros(vetorNumeros[2], vetorNumeros[3]);
    int mdcTotal = MDCDoisNumeros(mdc1e2, mdc3e4);
    
    printf("%d", mdcTotal);

    fclose(file);
    return 0;
}
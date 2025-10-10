// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)
#include <stdio.h>


int main(){
    int tamanho = 0;
    scanf("%d", &tamanho);
    // printf(" qual e o tamanho? %d\n", tamanho);
    // tamanho++;
    
    int conjunto[tamanho];
    
    
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &conjunto[i]);
        //printf("recebi");
    }
    
    
    for (int j = tamanho - 1; j >= 0; j--){
        printf("%d\n", conjunto[j]);
    }
    
}
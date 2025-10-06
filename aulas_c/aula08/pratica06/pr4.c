// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)

#include <stdio.h>
#include <string.h>

int main() {
    
    char c[50];
    char result[50];
    fgets(c, sizeof(c), stdin);
    // printf("char c %s\n", c);
   // printf("tamanho c: %d\n", strlen(c));
    
    int tamanho = strlen(c);
    
    int i = 0;
    int j = tamanho -1;
    while(i < tamanho){
        
        result[i] = c[j];
        // printf("letra %c\n ", result[i]);
        
        i++;
        j--;
    }
    
    result[tamanho] = c[tamanho]; // Eu tinha que arrumar um jeito de copiar o \0
    
    printf("%s", result);
    
    return 0;
}
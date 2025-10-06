// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)

#include <stdio.h>
#include <string.h>

int main() {
    
    char c[50];
    fgets(c, sizeof(c), stdin);
    // printf("char c %s\n", c);
   // printf("tamanho c: %d\n", strlen(c));
   
   int tamanho = strlen(c);
   int palavras = 1;
   
   for(int i = 0; i < tamanho; i++){
       
       int codCarac = c[i];
       
       if (codCarac == 32){
           palavras++;
       }
   }
    
    
    printf("%d\n", palavras);
    return 0;
}
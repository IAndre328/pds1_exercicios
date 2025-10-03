#include <stdio.h>
int main(){
    
    int tamanhos[15];
    
    for (int i = 0; i <= 14; i++){
        scanf("%d", &tamanhos[i]);
        // printf("%d ", tamanhos[i]);
    }
    

    
    int numMaior = 0;
    int numMenor = 0;
    for (int j = 0; j <= 14; j++){
        int atual = tamanhos[j];
        int maior = 0;
        int menor = 0;
        
           for (int k = 0; k <= 14; k++){
               
                if (atual >= tamanhos[k]){
                    
                    maior++;   
                } else {
                    
                    menor++;
                    
                }
                
           }
           
           
           if (maior == 15){
               numMaior = atual;
           } 
           if (menor == 14){
               numMenor = atual;
           }
           
        } 
        
        printf("Maior: %d\n", numMaior);
        printf("Menor: %d\n", numMenor);
        
}
    
    

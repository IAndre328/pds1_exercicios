// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)


#include <stdio.h>

void printVetor(int tamanho, int* V){
    for(int v = 0; v < tamanho; v++) printf("%d ", V[v]);
    printf("%d", V[tamanho-1]);
}

int freioSort(int tamanho, int* V){
    
    int frear = 1;
    
    for(int i = 0; (i < tamanho && frear > 0); i++){
        
        for (int j = i + 1; (j < tamanho  && frear > 0); j++){
            frear = (V[i] >= V[j] ? 1 : 0);
        }
        
    }
    
    return frear;
    
}


void Sort(int tamanho, int* V){
    
    int operacoes = 0;
    
    int freio = 0;
     
    while (freio < 1){
       
       for(int j = operacoes % 2; j < tamanho - 1; j+= 2){
           
           int n1 = V[j];
           int n2 = V[j + 1];
           
           if (n2 > n1){
               V[j] = n2;
               V[j + 1] = n1;
           }
           //printf("Numeros %d %d\n", n1, n2);
           
       }
      
      operacoes++;
      freio = freioSort(tamanho, V);
   }
   
   
        
        
        
}






int main(){
    
    int tamanho = 0;
    scanf("%d", &tamanho);
    
    int conjunto[tamanho];
    for(int i = 0; i < tamanho; i++) scanf("%d", &conjunto[i]);
    
    Sort(tamanho, conjunto);
    printVetor(tamanho, conjunto);
    
    
}
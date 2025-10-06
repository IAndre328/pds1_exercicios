#include <stdio.h>
#include <string.h>


void removechar(char* a, int tamanho, char c){
    // escreva sua solução aqui
    int codCaractereRef = c;
    
    
    int done = 0;
    int i = 0;
   
    
    
    
    while((i < tamanho) && (done == 0)){
        int caracterAnalise = a[i];

        
        if(caracterAnalise == codCaractereRef){
            
            while(i < tamanho){
                a[i] =  a[i + 1];
                i++;
            }
            
            done++;
            
        }
        
        i++;
    }
    
    

}

#include <stdio.h>

int verif(int x){
    
    if (x % 2 == 0){
        
        printf("%d e par.", x);
    } else {
        
        printf("%d e impar.", x);
    }
}

void par_ou_impar(int num){

   
    
    if (num > 0){
        
        verif(num);
    } else {
        
        printf("ERRO: numero invalido.");
        
    }
}
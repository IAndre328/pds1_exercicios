#include <stdio.h>

int main(){
    int maxPermitido;
    int registrado;
    
    scanf("%d %d", &maxPermitido, &registrado);
    
    if (registrado <= maxPermitido){
        
        printf("Sem Infracao");
        
    } else if(registrado <= ((int)(maxPermitido * 1.2) ) ){
        
        printf("Infracao Media");
        
    } else if(registrado <= ((int)(maxPermitido * 1.5) ) ){
        
        printf("Infracao Grave");
    }else {
        
        printf("Infracao Gravissima");
    }
}
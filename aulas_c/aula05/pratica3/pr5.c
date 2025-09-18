#include <stdio.h>

int main(){
    
    unsigned long long maiorX = 0;
    long long menorX = 1;
    menorX <<= 63;
    
    

    printf("Menor: %lld\nMaior: %llu\n ", menorX, ~maiorX);
    
    
    
}
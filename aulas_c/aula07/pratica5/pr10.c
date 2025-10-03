#include <math.h>
#include <stdio.h>

int multNum(int num, int casa){
    
    for (int i = 1; i < casa; i++) {
        num *= 10;
    }
    return num;
    
}

int inverte(unsigned int n){
    
    int casasDecimais = 1;
    unsigned int tempN = n;
    while (tempN > 9){
        
        tempN /= 10;
        casasDecimais++;
        
    }
    
    unsigned int result = 0;
    for (int i = 0; i < casasDecimais; i++){
        
        int digito = (n % 10);
        n /= 10;
       // printf("%d\n", digito);
        
        result += multNum(digito,casasDecimais-i);
        
    }
    return result;
    
}
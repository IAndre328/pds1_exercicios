#include <stdio.h>
#include <math.h>


int main(){
    
    double logbase(double num, double base){
        return log(num) / log(base);
    }
    
    printf("%f\n", logbase(8,2));
    
}

// Achei importante documentar isso. O logarítmo de um número em uma base é igual ao logarítmo de um número, dividido pelo logarítmo da base. Isso pode ser importante algum dia.
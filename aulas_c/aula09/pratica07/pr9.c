#include <stdio.h>

int verificamatrizigual(int linA, int colA, int A[linA][colA], int linB, int colB, int B[linB][colB]) {
    
    int igual = 1;
    
    if ((linA != linB) || (colA != colB)){
        
        igual = 0;
        return igual;
        
    } else {
        
        for (int i = 0; i < linA; i++){
        
            for (int j = 0; j < colA; j++){
            
                igual &= (A[i][j] == B[i][j]);
            }
        }
    }
    
    
    return igual;
}
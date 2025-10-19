// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)

#include <stdio.h>

int main(){
    
    int lin = 0;
    int col = 0;
    
    scanf("%d", &lin);
    scanf("%d", &col);
    
    int A[lin][col];
    int B[lin][col];
    
    for (int i = 0; i < lin; i++){
        
        for (int j = 0; j < col; j++){
            int entrada = 0;
            scanf("%d", &entrada);
            A[i][j] =  entrada;
            B[i][j] = -(entrada);
            
            if(j < col - 1) {
                
                printf("%d ", B[i][j]);
                
            } else {
                
                printf("%d\n", B[i][j]);
                
            }
            
        }
        
    }
    
    
    
    
    
    
    
    
    return 0;
}
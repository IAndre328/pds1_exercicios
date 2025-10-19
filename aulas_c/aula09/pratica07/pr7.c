#include <stdio.h>

int main(){
    
    int col = 0;
    int lin = 0;
    
    scanf("%d", &lin);
    scanf("%d", &col);

    int matriz[lin][col];
    int maiorLin = 0;
    int maiorNum = 0;

    
    for(int i = 0; i < lin; i++){
        
        for(int j = 0; j < col; j++){
            int entrada = 0;
            scanf("%d", &entrada);
            
            matriz[i][j] = entrada;
            //printf("Teste %d %d\n", entrada, maiorNum);
            if(i > 0 || j > 0){
                if (entrada > maiorNum){
                    maiorNum = entrada;
                    maiorLin = j;
                } else if (entrada == maiorNum){
                    
                    maiorLin = maiorLin < j ? maiorLin : j;
                
                }
            } else {
                maiorNum = entrada;
                maiorLin = j;
            }
        
        }
    
    }
    
 
    printf("%d\n", maiorLin);
}
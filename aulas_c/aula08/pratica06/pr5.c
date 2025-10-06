// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)
#include <stdio.h>
#include <string.h>


void stringESub(char* sub, char* inte){
    int tamanhoInteira = (strlen(inte) - 1);
    int tamanhoSub = (strlen(sub) - 1);
    
    int i = 0;
    int j = 0;
    int subCoincide = 0;
    while((i <= tamanhoInteira) && (subCoincide < tamanhoSub)){
        subCoincide = 0;
        
        // printf("while de cima %c %c\n", inte[i], sub[0]);
        
        if (inte[i] == sub[0]){
            
            while(j < tamanhoSub){
                
              //  printf("jjj %d\n", j);
                
                if(inte[i + j] == sub[j]){
                    subCoincide++;
                    printf("coincide\n");
                    
                   
                  // printf("ii %c\n", inte[i + j]);
                   // printf("sub %d %c\n", j,sub[j]);
                }
                
            j++;
                
            }
                
            
            
        }
        
        i++;
    }
    
    if(subCoincide >= tamanhoSub){
        printf("E substring");
        
    } else {
        
        printf("Nao e substring");
        
    }
    
    
}


int main() {
    char stringInteira[50];
    fgets(stringInteira, sizeof(stringInteira), stdin);    
    
    char subString[50];
    fgets(subString, sizeof(subString), stdin);    
    
    
    stringESub(subString, stringInteira);
    
    
    

    return 0;
}
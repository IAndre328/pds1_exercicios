// escreva sua solucao aqui :)
#include <stdio.h>

int contacarateresalfa(char* ptr, int size){
    
    // printf("string %s\ntamanho %d\n", ptr, size);
    
    int s = size - 1;
    int resultSize = 0;
   
    
    for (int i = 0; i <= s; i++){
        int alpha = 0;
       // printf("iii %d\n", i);
        char codCaracter = ptr[i];
        
        if (codCaracter >= '0' && codCaracter <= '9'){
            
            resultSize++;
            
        } else if (codCaracter >= 'a' && codCaracter <= 'z'){
            
            resultSize++;
            
        }else if (codCaracter >= 'A' && codCaracter <= 'Z'){
            
            resultSize++;
            
        }
        
    }      

  //  printf("Size final %d\n", resultSize);
    return resultSize;
}

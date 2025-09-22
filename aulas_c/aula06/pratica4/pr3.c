#include <stdio.h>

int main(){
    
    char sexo;
    int idade;
    int tempoC;
    
    scanf("%d %d %c", &idade, &tempoC, &sexo);
    
    if(sexo == 'M'){
        if (idade >= 65 || (idade >= 60 && tempoC >= 35) ){
            printf("Pode aposentar");
        }else {
            printf("Nao pode aposentar");
        }
    } else if (sexo == 'F'){
        if (idade >= 60 || (idade >= 55 && tempoC >= 30) ){
            printf("Pode aposentar");
        }else {
            printf("Nao pode aposentar");
        }
        
    }
}
#include <stdio.h>

int verifAno(int a){
    if (
        ((a % 4) == 0) && ((a % 100) != 0) ||
        ((a % 400) == 0)
    ){
        printf("\nO ano de %d e bissexto.", a);
    } else{
        printf("\nO ano de %d nao e bissexto.", a);
    }
    
}

int main(){
    
    int ano;
    
    printf("Digite um ano:");
    scanf("%d" ,&ano);
    
    verifAno(ano);
    
    
    
}
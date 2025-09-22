#include <stdio.h>



int main(){
    
    float precoIni;
    char idUF;
    float taxa;
    float precoFim;
    
    scanf("%f %c", &precoIni, &idUF);
    
    switch (idUF){
        case 'G':
            taxa = 1.07;
            precoFim = precoIni * taxa;
            printf("O valor em MG seria de R$%.2f", precoFim);
            break;
        
        case 'P':
            taxa = 1.12;
            precoFim = precoIni * taxa;
            printf("O valor em SP seria de R$%.2f", precoFim);
            break;
        
        case 'J':
            taxa = 1.15;
            precoFim = precoIni * taxa;
            printf("O valor em RJ seria de R$%.2f", precoFim);
            break;
            
        case 'S':
            taxa = 1.08;
            precoFim = precoIni * taxa;
            printf("O valor em MS seria de R$%.2f", precoFim);
            break;
        
        
        default:
            printf("Estado invalido");
            return 1;
            break;
    }
    
    
    
}
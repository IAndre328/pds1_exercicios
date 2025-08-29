#include <stdio.h>

float rendimento(float valor, float juros){
        float rend = (valor*juros) + valor;
        //printf("%f\n", rend);
        return rend;
    }

int main(){
    float valorIni = 789.54;
    float juro = 0.56 / 100; // 0,56% não é 0.56 '-'
    float valorVariavel = 0;
    
    
    // Primeiro mês
    valorVariavel = valorIni;
    valorVariavel = rendimento(valorVariavel,juro);
    //printf("%.2f", valorVariavel);
    
    // Segundo mês
    valorVariavel += 303.20;
    valorVariavel = rendimento(valorVariavel,juro);
    //printf("%.2f", valorVariavel);
    
    // Terceiro mês
    valorVariavel -= 58.25;
    valorVariavel = rendimento(valorVariavel,juro);
   // printf("%.2f", valorVariavel);
    
    // Quarto mês
    printf("%.2f", valorVariavel);
    
}
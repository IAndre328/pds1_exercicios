#include <stdio.h>

float imc(float alt, float peso){
    return peso / (alt * alt);
}

float variacaoPeso(float alt, float pes, float _imc){
    float vpeso;
    float pesoMaximo = 25 * alt * alt;
    float pesoMinimo = 18.5 * alt * alt;
    if (_imc > 25){
        vpeso = pes - pesoMaximo;
    } else if (_imc < 16){
        vpeso = pesoMinimo - pes;
    } else { 
        return 0; 
    }
    return vpeso;
}

int main(){
     float altOlivia = 1.76;
     float pesOlivia = 45;
     float altBrutus = 1.84;
     float pesBrutus = 122;
     
     float imcOlivia = imc(altOlivia, pesOlivia);
     float imcBrutus = imc(altBrutus, pesBrutus);

     
     printf("%.1f %.1f",variacaoPeso(altBrutus, pesBrutus, imcBrutus), variacaoPeso(altOlivia, pesOlivia, imcOlivia));
    
    
}
#include <stdio.h>

float imc(float alt, float peso){
    return peso / (alt * alt);
}


float ganhoPeso(float alt, float pes, float imc){
    float vpeso;
    float pesoMinimo = 18.5 * alt * alt;
    vpeso = pesoMinimo - pes;
    return vpeso;

}

float perderPeso(float alt, float pes, float imc){
    float vpeso;
    float pesoMaximo = 25 * alt * alt;
    vpeso = pes - pesoMaximo;
    return vpeso;

}

int main(){
     float altOlivia = 1.76;
     float pesOlivia = 45;
     float altBrutus = 1.84;
     float pesBrutus = 122;
     
     float imcOlivia = imc(altOlivia, pesOlivia);
     float imcBrutus = imc(altBrutus, pesBrutus);

     
     printf("%.1f %.1f\n",perderPeso(altBrutus, pesBrutus, imcBrutus), ganhoPeso(altOlivia, pesOlivia, imcOlivia));
    
    
}
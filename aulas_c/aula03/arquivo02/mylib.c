#include "mylib.h"
// Inlcui esse biblioteca personlizada

// Declarando uma constante
#define M_PI 3.14159

// Implemeta a função personalizada, nesse caso a soma de dois números inteiros
int soma(int a, int b) {
    return a + b;
}

// Função de teste: raio de um círculo
float raioCirc(float raio){
    float r = M_PI * raio * raio;
    return r;
}

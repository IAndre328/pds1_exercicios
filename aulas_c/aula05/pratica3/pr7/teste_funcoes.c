#include <stdio.h>
#include <stdlib.h>
#include "minhas_funcoes.h"




int main(int argc, char const *argv[]){

    int x;
    printf("\nDigite um valor inteiro: ");
    scanf("%d", &x);
    soma1(&x);
    printf("\nValor depois de chamar a função: %d", x);

    float a, b;
    printf("\nDigite os valores para troca: ");
    scanf("%f %f", &a, &b);
    troca(&a, &b);
    printf("\nValores depois de chamar a função: %.4f %.4f", a, b);

    long long tel = 0;
    printf("\nDigite o telefone: ");
    scanf("%lld", &tel);
    printf("\nDDD: %d", ddd(tel));


    return 0;
}

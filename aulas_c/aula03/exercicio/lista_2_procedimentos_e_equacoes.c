/*
    Aluno: André Rafael Batista
    Matrícula: 2025050539
*/

#include <stdio.h>
#include <math.h>
#define PI 3.1415926



    // Início do exercício geral
    // Início do exercício 1

    // letra a
float media(float a, float b, float c){
    return (a + b + c) / 3 ;
}

    // letra b
float mediaPonderada(float a, float b, float c){
    return (((a * 3) + (b * 4) + (c * 5)) / 3);
}

    // letra c
float perimetroCirc(float r){
    return 2 * PI * r;
}

    // letra d
float areaCirc(float r){
    return PI * r * r;
}

    // letra e
float areaTri(float b, float c){
    return (b * c) / 2; 
}

    // letra f
float areaCaixa(float a, float b){
    return a * b;
}

    // letra g
float volumeCaixa(float a, float b, float c){
    return a * b * c;
}

    // letra h
float areaCilindro(float r, float h){
    float area = perimetroCirc(r) * h;
    return area;
}

    // letra i
float volumeCilindro(float r, float h){
    float volume = areaCirc(r) * h;
    return volume;
}

    // letra j
float hipotenusa(float b, float c){
    return sqrt((b * b) + (c * c));
}

    // letra k
float raizPositiva(float a, float b, float c){
    float raiz = (( (b * -1) + (sqrt(b * b - (4 * a * c))))) / 2 * a;
    return raiz;
}


    // Fim do exercício 1




    // Início do exercício 2
int main(int argc, char const *argv[]){

    /* Teste da letra a */
    float m = media(1, 2, 3);
    printf("A média de a, b e c é: %f\n", m);

    // Teste da letra b
    float mp = mediaPonderada(1, 2, 3);
    printf("A média ponderada de a, b, e c, onde a tem peso 3, b tem peso 4 e c tem peso 5 é: %f\n", mp);

    // Teste da letra c
    float p = perimetroCirc(4);
    printf("O perímetro de um círculo de raio r é: %f\n", p);

    // Teste da letra d
    float ac = areaCirc(4);
    printf("A área de um círculo de área r é: %f\n", ac);

    // Teste da letra e
    float at = areaTri(3, 4);
    printf("A área de um triângulo de base b e altura c é: %f\n", at);

    // Teste da letra f
    float acx = areaCaixa(2, 3);
    printf("A área de uma caixa de dimensões a e b é: %f\n", acx);

    // Teste da letra g
    float vcx = volumeCaixa(2, 3, 4);
    printf("O volume de uma caixa de dimensões a, b e c é: %f\n", vcx);

    // Teste da letra h
    float acl = areaCilindro(4, 3);
    printf("A área de um cilindro de raio r e altura h é: %f\n", acl);

    // Teste da letra i
    float vcl = volumeCilindro(4, 12);
    printf("O volume de um cilindro de raio r e altura r é: %f\n", vcl);

    // Teste da letra j
    float h = hipotenusa(4, 6);
    printf("A hipotenusa de um triângulo de lados b e c é: %f\n", h);

    // Teste da letra k
    float rp = raizPositiva(1, -1, -12);
    printf("A raiz positiva de uma equação do segundo grau com a.x2 + b.x + c é: %f\n", rp);


    // Fim do exercício 2
    // Fim do exercício geral
}


    
    


    

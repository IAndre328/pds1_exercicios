// ALUNO: André Rafael Batista
// MATRÍCULA: 2025050539

#include <stdio.h>
#include <math.h>


int main(){

    
    // Início do exercício número 1
    
    // Letra a
        printf("O resultado de 3 + 4 é: %d\n", 3 + 4);
    
    // Letra b
        printf("O resultado de 7 dividido por 4 é: %d\n", 7/4);
    
    // Letra c
        printf("O resultado de 3 elevado à 2 é: %d\n", 3^2);
    
    // Letra d
        printf("O resultado de 5.3 vezes 2.1 é: %f\n", 5.3 * 2.1);
    
    // Letra e
        printf("O resultado de 2 * 5 - 2 é: %d\n", 2 * 5 - 2);

    // Letra f
        printf("O resultado de 2 + 2 * 5 é: %d\n", 2 + 2 * 5); 
    
    // Letra g
        printf("O resultado de (2 + 5) * 3 é: %d\n", (2 + 5) * 3);   
    
    // Letra h
        printf("O seno de 3.141502 é: %f\n", sin(3.141502));
    
    // Letra i
        printf("A raiz quadrade de 5 é: %f\n", sqrt(5));    
    
    // Letra j
        printf("O resultado de 1 + 2 + 3 é: %d\n", 1 + 2 + 3);
    
    // Letra k
        printf("O resultado de 1 * 2 * 3 é: %d\n", 1 * 2 * 3);   
    
    // Letra l
        printf("O resultado de (1 + 2 + 3) / 3.0 é: %f\n", (1 + 2 + 3) / 3.0);  
    
    // Letra m
        printf("O resultado da expressao (2 + 4) * (3 - 1) é: %d\n", (2 + 4) * (3 - 1));
    
    // Letra n
        printf("O resultado da expressao (9 / 3) + (3 * 2) é: %d\n", (9 / 3) + (3 * 2));
    
    // Letra o
        printf("O resultado da expressao sin(4.5) + cos(3.7) é: %f\n", sin(4.5) + cos(3.7));
    
    // Letra p
        printf("O resultado da expressao log(2.3) – log(3.1) é: %f\n", log(2.3) - log(3.1));    
    
    // Letra q
        printf("O resultado da expressao log(7) + (log(7) * log(7) – cos(log(7))) é: %f\n", log(7) + (log(7) * log(7) - cos(log(7)))  );    
    
    // Letra r
        printf("O resultado da conta (10.3 + 8.4)/50.3 - (10.3 + 8.4) é: %f\n", (10.3 + 8.4)/50.3 - (10.3 + 8.4));
    
    // Letra s
        printf("O resultado da conta (cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8)) é: %f\n", (cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8)));
    
    // Fim do exercício 1

    // Início do exercício 2
    float floA, floB, floC, floD;
    printf("Digite os números a, b, c, e d \n");
    scanf("%f %f %f %f", &floA, &floB, &floC, &floD);


    // Letra a
        printf("O resultado da soma a + b é: %f\n", floA + floB);
    
    // Letra b
        printf("O resultado da divisão a / c é: %f\n", floA / floC);

    // Letra c
        printf("O resultado da conta a elevado a 2 é: %f\n", floA*floA);

    // Letra d
        printf("O resultado da conta b * c é: %f\n", floB * floC);

    // Letra e
        printf("O resultado da conta a * b - c é: %f\n", floA * floB - floC );

    // Letra f
        printf("O resultado da conta a + b * c é: %f\n", floA * floB - floC );

    // Letra g
        printf("O resultado da conta (a + b) *c é: %f\n", (floA + floB) *floC);

    // Letra h
        printf("O resultado da conta seno de a é: %f\n", sin(floA));

    // Letra i
        printf("O resultado da raiz quadrada de a é: %f\n", sqrt(floA));

    // Letra j
        printf("O resultado da soma a + b + c é: %f\n", floA + floB + floC);

    // Letra k
        printf("O resultado da conta a * b * c é: %f\n", floA * floB * floC);

    // Letra l
        printf("O resultado da conta (a + b + c) / d é: %f\n", (floA + floB + floC)/ floD);

    // Letra m
        printf("O resultado da conta (a + b) * (a - d) é: %f\n", (floA + floB) * (floA - floD));

    // Letra n
        printf("O resultado da conta (b / c) + (a * d) é: %f\n",(floB / floC) + (floA * floD) );    

    // Letra o
        printf("O resultado da conta seno de b + cosseno de c é: %f\n", sin(floB) + cos(floC));
    
    // Letra p
        printf("O resultado da conta log(a) - loc(c) é: %f\n", log(floA) - log(floC));
    
    // Letra q
        printf("O resultado da conta log(a) + (log(b) * log(d) - cos(log(c))) é: %f\n", log(floA) + (log(floB) * log(floD) - cos(log(floC))));

    // Letra r
        printf("O resultado da conta (b + a)/c - (d + a) é: %f\n", (floB + floA)/floC - (floD + floA));

    // Letra s
        printf("O resultado da conta (cos(d) + sin(c)) * (cos(b) - sin(a)) é: %f\n", (cos(floD) + sin(floC)) * (cos(floB) - sin(floA)));

    // Fim do exercício 2

    // Início do exercício 3
        float a,b,c;
        printf("Digite os números a, b e c \n");
        scanf("%f %f %f", &a, &b, &c);
    
    // Letra a
        printf("A média de a, b e c é: %f\n", (a+b+c)/3);

    // Letra b
        printf("A média ponderada, onde a tem peso 3, b tem peso 4 e c tem peso 5 é: %f\n", ((a*3) + (b*4) + (c*5))/3);

    // Letra c
        printf("O perímetro de um círculo de raio a é: %.2f\n", (2 * 3.14159 * a));

    // Letra d
        printf("O raio de um círculo de raio a é: %.2f\n", (3.14159 * a * a));

    // Letra e
        printf("A área de um triângulo de base b e altura c é: %f\n", (b * c)/2);

    // Letra f
        printf("A hipotenusa de um triângulo retângulo cujos lados são b e c é: %.2f\n", sqrt((a * a) + (b * b)));

    // Letra g
        printf("%f\n", ( (b * -1) + (sqrt(b * b - (4 * a * c)) ) / 2  * a) );
        printf("As raízes de da equação do segundo grau definida por a.x2 + bx + c são: %f %f\n", (( (b * -1) + (sqrt(b * b - (4 * a * c))))) / 2 * a , (( (b * -1) - (sqrt(b * b - (4 * a * c))))) / 2 * a);
    

    
    // Fim do exercício 3
    // Final do exercício.

    // Considerações finais:
    /*
        Pessoalmente, achei este um exercício pessoalmente muito massante, mas acho normal pra quem está começando no ramo da programação. Ademais as funções de seno, cosseno e tangente retornam os ângulos em radianos, como não estava específico, tanto a entrada, quanto a saída estão em radianos
        Em segunda instância, teria me economizado uma boa dor de cabeça sabendo que para ajudar o gcc ler as funççoes de seno e cosseno é necessário colocar o parâmetro "-lm" na hora da compilação. EX: lista_1_Estruturas_basicas.c -o lista_1_Estruturas_basicas.out -lm
    */
    

}
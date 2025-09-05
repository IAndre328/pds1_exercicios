#define PI 3.141592
#include <stdio.h>

float cauchy(float x){
    float c = 1 / (PI * (1 + (x * x)));
    return c;
}

int getCauchy(){
    
    float recebeC, result;
    
    printf("Digite o valor para teste: ");
    scanf("%f\n", &recebeC);

    result = cauchy(recebeC);
    printf("Resultado: %f\n", result);



    return 0;
}

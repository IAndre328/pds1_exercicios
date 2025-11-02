#include <stdio.h>
#include <math.h>

typedef struct{
    
    float x;
    float y;
    
} Cordenadas;


void fillCordsWithInput(Cordenadas* c){
    //Zerando só por garantia
    c->x = 0;
    c->y = 0;
    
    scanf("%f %f", &c->x, &c->y);
    //printf("%f %f\n\n", c->x, c->y);
    
    
    
}

int isC2BiggerThanC1(Cordenadas* c1, Cordenadas* c2){
    //printf("Cheguei aqui");
    if((c2 -> x) <= (c1 -> x) || (c2 -> y) >= (c1 -> y)){
        
        printf("Coordenada Invalida\n");
        return 0;
        
    } else {
        
        
        return 1;
        
    }
    
    
}

// O inglês não deve estar 100% para módulo da diferença entre n1 e n2, mas é isso aí
float moduleDiferenceN1AndN2(float n1, float n2){
    
    return (sqrt(((n2 - n1) * (n2 - n1))));
    
}

int main(){
    
    Cordenadas c1,c2;
    
    fillCordsWithInput(&c1);
    
    do{
        
        fillCordsWithInput(&c2);
        
    } while (isC2BiggerThanC1(&c1, &c2) == 0);
    
    float width = moduleDiferenceN1AndN2(c1.x, c2.x);
    float height = moduleDiferenceN1AndN2(c1.y, c2.y);
    
    float area = width * height;
    float perimetro = (2 * width) + (2 * height);
    float diagonal = sqrt((width * width) + (height * height));
    
    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);
    printf("Diagonal = %.2f\n", diagonal);
    
}
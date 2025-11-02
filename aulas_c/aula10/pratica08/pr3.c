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

float isColiding(Cordenadas* c1, Cordenadas* c2, Cordenadas* ponto){
    
    
    float width = moduleDiferenceN1AndN2(c1 -> x, c2 -> x);
    float height = moduleDiferenceN1AndN2(c1 -> y, c2 -> y);
    /*
    
    int teste1 = (ponto -> x) >= (c1 -> x) ? 1 : 0;
    printf("(ponto -> x) >= (c1 -> x)? ", teste1);
    
    int teste2 = (ponto -> x) <= ((c1 -> x) + width) ? 1 : 0;
    printf("(ponto -> x) <= ((c1 -> x) + width)? ", teste2);
    
    int teste3 = (ponto -> y) >= (c1 -> y) ? 1 : 0;
    printf("(ponto -> y) >= (c1 -> y)? ", teste3);
    
    int teste2 = (ponto -> y) <= ((c1 -> y) + height) ? 1 : 0;
    printf("(ponto -> y) <= ((c1 -> y) + width)? ", teste4);
    
    */
    
 
    
    if(
        (ponto -> x) >= (c1 -> x) &&
        (ponto -> x) <= ((c1 -> x) + width) &&
        (ponto -> y) >= (c2 -> y) &&
        (ponto -> y) <= ((c2 -> y) + height) 
        ){
            
            return 1;
            
        } else {
            
            return 0;
            
        }
    
}

int main(){
    
    Cordenadas c1,c2, ponto;
    
    fillCordsWithInput(&c1);
    
    do{
        
        fillCordsWithInput(&c2);
        
    } while (isC2BiggerThanC1(&c1, &c2) == 0);
    
    fillCordsWithInput(&ponto);
    
    
    
    
    int colide = isColiding(&c1, &c2, &ponto);
    
    if(colide == 1){
        
        printf("O ponto pertence ao retangulo");
        
    } else {
        
        printf("O ponto nao pertence ao retangulo");
        
    }
    
}
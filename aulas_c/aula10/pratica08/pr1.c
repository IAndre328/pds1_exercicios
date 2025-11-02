#include <stdio.h>
#include <math.h>

typedef struct{
    
    float x;
    float y;
    
} Cordenadas;

float distanciaEntrePontos(Cordenadas *c1, Cordenadas *c2){
    
    // V de Variação
    float vx = (c2->x) - (c1->x);
    float vy = (c2->y) - (c1->y);
    
    float dist = sqrt((vx * vx) + (vy * vy));
    return dist;
    
}

int main(){
    
    Cordenadas cord_1;
    scanf("%f %f", &cord_1.x, &cord_1.y);
    //printf("%f %f\n", cord_1.x, cord_1.y);
    
    Cordenadas cord_2;
    scanf("%f %f", &cord_2.x, &cord_2.y);
    //printf("%f %f\n\n", cord_2.x, cord_2.y);
    
    float dist_c1_c2 = distanciaEntrePontos(&cord_1, &cord_2);
    printf("%.2f", dist_c1_c2);
    
    
}
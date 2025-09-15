#include "minhas_funcoes.h"
#include <stdio.h>

float testaTroca(float x, float y){
    float* end_x = &x;
    float* end_y = &y;
    
    troca(end_x, end_y);
    
    printf("%.4f %.4f", x, y);
    
}

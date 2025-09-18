#include "minhas_funcoes.h"
#include <stdio.h>

int testaSoma1(int x){
    
    int* ponteiro = &x;
    soma1(ponteiro);
    return *ponteiro;
}
// ALOCAÇÃO DINÂMICA
#include <stdlib.h>

int main(int argc, char const *argv[]){


    int* A = NULL;
    A = (int*) malloc(3 * sizeof(int)); //Cabem 3 inteiros aí

    int* B = NULL;
    B = (int*) calloc(B, 3 * sizeof(int));

    int* C = NULL;
    C = (int*) malloc(3 * sizeof(int));
    C = (int*) realloc(C, 3 * sizeof(int));

    free(A); 
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
/*                                                                                                            
    Cada memória alocada DEVE ser liberada depois
    Pilha -> região de memória estática
    Heap -> região de memória dinâmica

    se usar o malloc, ela vem um espaço com lixo
    Útil para costruir vetores de tamanho arbitrários


*/                                                                                                            
#include <stdio.h>


int main(int argc, char const *argv[]){
    
    int A = 2;

    // O int* cria um int capaz de guardar um endereço de memória
    int* X;

    // X vai receber o endereço de memória
    X = &A;

    // %p para exibir um ponteiro
    printf("%p\n ",X);

    // Dereferenciação -> use para pegar o valor que o endereço que X aponta
    // * Endereço apontado é diferente de endereço guardado
    printf("%d\n ", *X);

    // Isso não deveria funcionar
    printf("%d\n ", *(&A) );

    return 0;
}

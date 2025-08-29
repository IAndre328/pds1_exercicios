#include <stdio.h>

int main(){

    // const -> constante -> Seu valor não pode ser alterado posteriormente por atribuição
    const char letra1 = 'P';
    const char letra2 = 'D';
    const char letra3 = 'S';
    const char letra4 = '-';
    const char letra5 = '1';
    
    int soma = letra1 + letra2 + letra3 + letra4 + letra5;
    int mult = letra1 * letra2 * letra3 * letra4 * letra5;
    
    printf("%d %d", soma, mult);

 
    /* code */
    return 0;
}

#include <stdlib.h>

void preencherpseudoaleatoriamente(unsigned long long seed, unsigned int min, unsigned int max, int lin, int col, int M[lin][col]) {
    // escreva sua solução aqui
    // voce nao precisa capturar os dados do usuario com scanf nem printar a matriz
    
    srand(seed);
    for (int i = 0; i < lin; i++){
        
        for (int j = 0; j < col; j++){
            int random = min + (rand() % (max - min));
            M[i][j] = random;
        }
    }
}
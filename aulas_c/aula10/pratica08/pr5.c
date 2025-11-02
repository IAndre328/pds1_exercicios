#include <stdio.h>

typedef struct {
    char nome[16];
    char esporte[16];
    short idade;
    float altura;
} Atletas;

void fillAtletaWithInput(Atletas* a){

        scanf("%15s %15s %hd %f", a->nome, a->esporte, &a->idade, &a->altura);

}

void fillVetorAtletasWithInput(Atletas *vetorA, int qtdaltetas){

     for (int j = 0; j < qtdaltetas; j++){

        Atletas atleta;
        fillAtletaWithInput(&atleta);

        vetorA[j] = atleta;
        
    }

}

int retornarAtletaMaisAlto(Atletas *vetorA, int qtdaltetas){
    
    int maiorIndex = 0;
    for (int j = 0; j < qtdaltetas; j++){

        if(vetorA[j].altura > vetorA[maiorIndex].altura){

            maiorIndex = j;

        }
        
    }
    

    return maiorIndex;
}

int retornarAtletaMaisVelho(Atletas *vetorA, int qtdaltetas){
    
    int maiorIndex = 0;
    for (int j = 0; j < qtdaltetas; j++){

        if(vetorA[j].idade > vetorA[maiorIndex].idade){

            maiorIndex = j;

        }
        
    }
    

    return maiorIndex;
}

int main(){

    int numatletas = 5;

    Atletas atletas[numatletas];

   fillVetorAtletasWithInput(atletas, numatletas);
    int maisAlto = retornarAtletaMaisAlto(atletas, numatletas);
    int maisVelho = retornarAtletaMaisVelho(atletas, numatletas);

    printf("Mais alto: %s\n", atletas[maisAlto].nome);
    printf("Mais velho: %s", atletas[maisVelho].nome);

    
    

    /* code */
    return 0;
}

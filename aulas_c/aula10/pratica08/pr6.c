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

void organizarAtletaMaisVelho(Atletas *vetorA, Atletas *vetorP,int qtdaltetas){
    
    int maiorIndex = 0;

    for (int k = 0; k < qtdaltetas; k++){
    
        for (int j = 0; j < qtdaltetas; j++){

            if(vetorA[j].idade > vetorA[maiorIndex].idade){

                maiorIndex = j;

            }
        }
        vetorP[k] = vetorA[maiorIndex]; 
        vetorA[maiorIndex].idade = -1;

    }
    

    
    
    
    
    
}

int main(){

    int numatletas = 5;

    Atletas atletas[numatletas];
    Atletas podio[numatletas];


    fillVetorAtletasWithInput(atletas, numatletas);
    
    organizarAtletaMaisVelho(atletas, podio,numatletas);

    for (int l = 0; l < numatletas; l++){

        printf("%d- %s\n", (l+1), podio[l].nome);
    }
    


    
    

    
    
    

    /* code */
    return 0;
}

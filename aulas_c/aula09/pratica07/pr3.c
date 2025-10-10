// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)


#include <stdio.h>


void intersecaoVetor(int* a, int sizeA, int* b, int sizeB){

    for (int k = 0; k < sizeA; k++){
        unsigned int alunoK = a[k];
        //printf("aluno k %ud\n", alunoK);

        for (int l = 0; l < sizeB; l++){
            unsigned int alunoL = b[l];
            //printf("aluno l %ud\n", alunoL);

            if (alunoK == alunoL) printf("%d ", alunoK);
        }
        
    }

}


int main()
{
    /* code */
     
    int qtd1 = 0;
    scanf("%d", &qtd1);
    

    unsigned int alunosAEDS1[qtd1];

    for (int i = 0; i < qtd1; i++){
        
        scanf("%ud", &alunosAEDS1[i]);

    }

   
   
    int qtd2 = 0;
    scanf("%d", &qtd2);
    

    unsigned int alunosCALC1[qtd2];

    for (int j = 0; j < qtd2; j++){
        
        scanf("%d", &alunosCALC1[j]);

    }

   // printf("Cheguei aqui\n");
    intersecaoVetor(alunosAEDS1, qtd1, alunosCALC1, qtd2);



    return 0;
}

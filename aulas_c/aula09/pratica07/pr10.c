// coloque aqui o seu codigo :)
// lembre que nesse VPL voce tem que definir o seu proprio main!
// (e importar as bibliotecas necessarias)

#include <stdio.h>

// tamanho de linhas + 2?

void imprimeDireita(int lin, int col, int matriz[lin][col], int matrizB[lin][col],int ciclo, int* i, int* j){
    
    //printf("iii %d\n", *i);
    //printf("jjj %d\n ", *j);
    
    
    
    do{
        
        
        printf("%d ", matriz[*i][*j]);
        matrizB[*i][*j] = matriz[*i][*j];
        *j = *j + 1;
        
    }while(*j < (col - (ciclo + 1)));
    
    
}


void imprimeDescendo(int lin, int col, int matriz[lin][col], int matrizB[lin][col],int ciclo, int* i, int* j){
    
    do{
        
        
        printf("%d ", matriz[*i][*j]);
        matrizB[*i][*j] = matriz[*i][*j];
        *i = *i + 1;
        
    }while(*i < (lin - (ciclo + 1)));
    
}

void imprimeEsquerda(int lin, int col, int matriz[lin][col], int matrizB[lin][col],int ciclo, int* i, int* j){
    
    
    do{
        
        
        printf("%d ", matriz[*i][*j]);
        matrizB[*i][*j] = matriz[*i][*j];
        *j = *j - 1;
        
    }while(*j > ciclo);
    
    
}


void imprimeSubindo(int lin, int col, int matriz[lin][col], int matrizB[lin][col],int ciclo, int* i, int* j){
    
    
    //printf("iii %d\njjj %d\n", *i, *j);
    
    do{
        
        printf("%d ", matriz[*i][*j]);
        matrizB[*i][*j] = matriz[*i][*j];
        *i = *i - 1;
        
    }while(*i > (ciclo + 1));
    
    
    
    
}

int verificarIgualdade(int lin, int col, int A[lin][col], int B[lin][col]){
    
    int igual = 1;
    
    for (int x = 0; x < lin && igual == 1; x++){
        
        for(int z = 0; z < col && igual == 1; z++){
         
            igual &= (A[x][z] == B[x][z]);
               
        }
        
    }
    
    return igual;
}

int main (){
 
    int lin = 0;
    int col = 0;
    
    scanf("%d", &lin);
    scanf("%d", &col);
    
    
    int matriz[lin][col];
    int matrizB[lin][col];
    
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            int entrada = 0;
            scanf("%d", &entrada);
            matriz[i][j] = entrada;
        }
    }
    
    
    int i = 0;
    int j = 0;
    int ciclo = 0;
    int done = 0;
    
   while(done == 0){
     
    done = verificarIgualdade(lin, col, matriz, matrizB);
    
    if (done == 0) imprimeDireita(lin, col, matriz, matrizB,ciclo, &i, &j);
    
    if (done == 0) imprimeDescendo(lin, col, matriz, matrizB, ciclo, &i, &j);
    
    if (done == 0) imprimeEsquerda(lin, col, matriz, matrizB, ciclo, &i, &j);
    
    if (done == 0) imprimeSubindo(lin, col, matriz, matrizB, ciclo, &i, &j);
    
    ciclo++;
       
   }
    
    
    
}
    


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_ALUNO 21

typedef struct{
    
    char nome[TAM_MAX_ALUNO];
    int n1, n2, n3, n4;
    float media;
    
}ALUNO;


int inserirAlunoNoVetorAlunos(ALUNO** turma, int* qtdAlunos, ALUNO aluno){
    
    ALUNO* tempVetor = (ALUNO*)realloc(*turma, (*qtdAlunos + 1) * sizeof(ALUNO));
    
    if(tempVetor == NULL){
        printf("Erro ao alocar memória ao vetor");
        return 1;
    }
    
    *turma = tempVetor;
    
    strcpy((*turma)[*qtdAlunos].nome, aluno.nome);
    (*turma)[*qtdAlunos].n1 = aluno.n1;
    (*turma)[*qtdAlunos].n2 = aluno.n2;
    (*turma)[*qtdAlunos].n3 = aluno.n3;
    (*turma)[*qtdAlunos].media = aluno.media;
    
    (*qtdAlunos)++;
    return 0;
}

int readVetorComArquivo(ALUNO** turma, int* qtdAlunos, FILE* arq){
    
    // TEMPS
    ALUNO temp;
    char nome[TAM_MAX_ALUNO];
    int n1, n2, n3, n4;
    float media;
    
    int itensLidos = 0;
    while((itensLidos = fscanf(arq, "%s %d %d %d %d", nome, &n1, &n2, &n3, &n4)) == 5){
        
        
        if (itensLidos != 5){
            if(itensLidos > 0){
                
                printf("Não foi possível ler 1 ou mais ítens");
                return 1;
                
            } else {
                
                printf("Não foi possível ler nenhum ítem");
                return 1;
                
            }
        }
        
        
        if (
            (n1 < 0 || n1 > 100) ||
            (n2 < 0 || n2 > 100) ||
            (n3 < 0 || n3 > 100) ||
            (n4 < 0 || n4 > 100)
            
            ){
                
                printf("Um ou mais alunos estão com notas inválidas");
                return 1;
            }
            
            strcpy(temp.nome, nome);
            temp.n1 = n1;
            temp.n2 = n2;
            temp.n3 = n3;
            temp.n4 = n4;
            temp.media = ((float)n1 + n2 + n3 + n4) / (4.0);
            
            //printf("%s %d %d %d %d\n", temp.nome, temp.n1, temp.n2, temp.n3, temp.n4);
            
            int ianva = inserirAlunoNoVetorAlunos(turma, qtdAlunos, temp);
            if (ianva == 1) return 1;
    }
    
    return 0;
}

void printAlunosAprovados(ALUNO* turma, int qtdAlunos){
    
    for (int i = 0; i < qtdAlunos; i++){
        
        if (turma[i]. media >= 60){
            printf("Nome: %s - Média: %.2f\n", turma[i].nome, turma[i].media);
        }
        
    }
    
}
    
int main(){
    
    FILE* arq;
    arq = fopen("notas.txt", "r");
    
    if (arq == NULL){
        perror("Não foi possível abrir o arquivo");
        return 1;
    }
    
    
    ALUNO* turma = NULL;
    int qtdAlunos = 0;
    
    int rvca = readVetorComArquivo(&turma, &qtdAlunos, arq);
    if (rvca == 1) return 1;
    
    printAlunosAprovados(turma, qtdAlunos);
    
    
    fclose(arq);
    return 0;
}
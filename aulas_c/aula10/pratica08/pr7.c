#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[16];
    char local[16];
    int dia, mes, ano;
} Eventos;

void fillEventosWithInput(Eventos* e){

    // Consume a quebra de linha residual do scanf anterior (se houver)
    // O problema está aqui, mas vamos resolver na chamada principal.

    fgets(e->nome, sizeof(e->nome), stdin);
    // Remover o \n do fgets (opcional, mas boa prática)
    e->nome[strcspn(e->nome, "\n")] = 0; 

    fgets(e->local, sizeof(e->local), stdin);
    // Remover o \n do fgets (opcional, mas boa prática)
    e->local[strcspn(e->local, "\n")] = 0; 
    
    // O scanf para a data não precisa de correção imediata, pois 
    // será seguido por um fgets na próxima iteração ou a chamada final.
    scanf("%d %d %d", &e->dia, &e->mes, &e->ano);
    
    // Limpa o '\n' que o scanf DEIXA no buffer para a próxima iteração
    // ou para o scanf final do main.
    while (getchar() != '\n' && !feof(stdin));
    
    //printf("Cheguei aqui %d", e->dia);

}

void fillVetorEventosWithInput(Eventos* vetorE, int qtdeventos){

     for (int j = 0; j < qtdeventos; j++){

        Eventos evento;
        fillEventosWithInput(&evento);

        vetorE[j] = evento;
        
    }

}

int main(){

    int qtdEventos = 0;
    scanf("%d", &qtdEventos);
    
    while (getchar() != '\n' && !feof(stdin));

    Eventos guardaEventos[qtdEventos];
    Eventos eventosNoDia[qtdEventos];

    fillVetorEventosWithInput(guardaEventos, qtdEventos);

    int diaParaConsulta = 0, mesParaConsulta = 0, anoParaConsulta = 0;

    scanf("%d %d %d", &diaParaConsulta, &mesParaConsulta, &anoParaConsulta);

    int matchIndex = -1;
    int eNoDia = 0;
    // e de evento

    for (int i = 0; i < qtdEventos; i++){
        //printf("%d\n", guardaEventos[i].dia);
        
        if (
            guardaEventos[i].dia == diaParaConsulta &&
            guardaEventos[i].mes == mesParaConsulta &&
            guardaEventos[i].ano == anoParaConsulta
        ){
            matchIndex = i;
            eventosNoDia[eNoDia] = guardaEventos[i];
            eNoDia++;
        }
        
        
    }

    if (matchIndex == -1){

        printf("Nenhum evento encontrado!");

    } else {

        for (int k = 0; k < eNoDia; k++){

            printf("%s\n %s\n", eventosNoDia[k].nome, eventosNoDia[k].local);
        
        }
        

    }
    
    
}    
#include <stdio.h>


#include "deck.h"
#include "entities.h"
#include "enemies.h"
#include "combat.h"

void printarStatsDosInimigos(){

    for (int i = 0; i < ativosInimigos; i++)
    {
        printf("Vida do inimigo %d: %d\n", i, listaInimigos[i].vidaAtual);
    }
    
}


void darDano(Card card, Entity* target, int targetIndex, PLAYER* playerState){
    printf("Vou começar a dar dano no INIMIGO: %d\n", listaInimigos[playerState->selectedEnemy].vidaAtual);
    int danoRestante = card.qtdTipo;
    printf("Quantidade custo da carta, aka dano: %d\n", card.custo);
    
    // --- LÓGICA DO DANO ---
    
    // 1. Aplica o dano ao escudo
    if (target->escudoAtual > 0) {
        if (danoRestante >= target->escudoAtual) {
            danoRestante -= target->escudoAtual;
            target->escudoAtual = 0;
        } else {
            target->escudoAtual -= danoRestante;
            danoRestante = 0; // Todo o dano foi absorvido pelo escudo
        }
    }

    // 2. Aplica o dano restante à vida
        
        printf("Dano restante depois do escudo: %d\n", danoRestante);
        if (danoRestante > 0) {
            printf("Aplicando %d de dano na vida da criatura %d (Indice: %d)\n", danoRestante, target->vidaAtual, targetIndex); 
            target->vidaAtual -= danoRestante;
        }
        
        
        // listaInimigos[playerState->selectedEnemy].vidaAtual -= danoRestante;
        // listaInimigos[1].vidaAtual -= danoRestante;
    
    
    // --- LÓGICA DE MORTE ---

    // Garante que a vida não seja negativa e verifica se a criatura morreu
    if (target->vidaAtual <= 0) {
        printf("Entidade no indice %d derrotada! Removendo...\n", targetIndex);
                
        RemoveEntityAtIndex(targetIndex); // Remove a entidade e decrementa ativosInimigos

        if(ativosInimigos > 0){

           if (playerState->selectedEnemy >= ativosInimigos) {
            playerState->selectedEnemy = ativosInimigos - 1;
            } 
            
        } else {
            playerState->selectedEnemy = -1;
        }
                
                
                
    }
    printarStatsDosInimigos();
}

void darEscudo(Card card, Entity* reciever){

    reciever->escudoAtual += card.qtdTipo;

    if (reciever->escudoAtual >= reciever->escudoMax){

        reciever->escudoAtual = reciever->escudoMax;
        
    }

}

void darCura(Card card, Entity* reciever){

    reciever->vidaAtual += card.qtdTipo;

    if (reciever->vidaAtual >= reciever->vidaMax){

        reciever->vidaAtual = reciever->vidaMax;
        
    }

}


void processarCarta(Card* card, int cardIndex, PLAYER* jogador){

    printf("Chegou no processarCarta o custo: %d\n", card->custo);
    if (card->custo > jogador->entidade.qtdElixir){
        printf("Você não tem elixir para jogar essa carta\n");
        return;
    }

    switch (card->tipo){

    case 'A':
        
        darDano(*card, &listaInimigos[jogador->selectedEnemy], jogador->selectedEnemy, jogador);
        
        break;
    
    case 'D':
        darEscudo(*card, &jogador->entidade);
        break;
    
    case 'C':
        darCura(*card, &jogador->entidade);
        break;

    case 'E':
        printf("Usando Carta Especial: Comprar 5 cartas\n");
        int cartasCompradas = 0;
        // Tenta comprar 5 cartas, parando se a mão encher ou o baralho acabar
        for(int i = 0; i < 5; i++){
            MoverCartaEntrePilhas(jogador->hand, 
                          &jogador->handSize, 
                          i, 
                          jogador->discardPile, 
                          &jogador->discardSize); 

            if (ComprarCarta(jogador)){
                cartasCompradas++;
            } else {
                break;
            }
        }
        int teste = ComprarCarta(jogador);
        printf("Total de cartas compradas: %d\n", cartasCompradas);
        break;
    default:
        printf("Não existe esse tipo de carta\n");
        return;
    }

    printf("Quantidade de elixir a ser retirado %d\n", card->custo);
    jogador->entidade.qtdElixir -= card->custo;
    printf("Quantidade de elixir restante %d\n", jogador->entidade.qtdElixir);

    
    
    // Move da pilha da mão para a de descarte, aka discartar uma carta
    MoverCartaEntrePilhas(jogador->hand, 
                          &jogador->handSize, 
                          cardIndex, 
                          jogador->discardPile, 
                          &jogador->discardSize); 

    if (jogador->selectedHandIndex >= jogador->handSize) {
        jogador->selectedHandIndex = jogador->handSize - 1;
    }
    if (jogador->selectedHandIndex < 0) {
        jogador->selectedHandIndex = 0;
    }

    if (jogador->selectedEnemy >= ativosInimigos) {
        jogador->selectedEnemy = ativosInimigos - 1; // Seleciona o novo último inimigo
    }
    if (ativosInimigos == 0) {
        jogador->selectedEnemy = -1; // Deseleciona se não houver mais inimigos
    }
}

int ComprarCarta(PLAYER* jogador) {
    
    // 1. Verificar se a mão está cheia
    if (jogador->handSize >= TAM_MAX_MAO) {
        printf("Mão cheia! Nenhuma carta comprada.\n");
        return 0; // 0 cartas compradas
    }
    
    // 2. Se o deck estiver vazio, reembaralhar o descarte
    if (jogador->deckSize == 0) {
        if (jogador->discardSize > 0) {
            printf("Baralho vazio. Reembaralhando descarte...\n");
            
            // Move todas as cartas do descarte para o baralho
            for (int i = 0; i < jogador->discardSize; i++) {
                // Move a carta para o baralho (destArray é jogador->deck)
                jogador->deck[jogador->deckSize++] = jogador->discardPile[i];
            }
            jogador->discardSize = 0; // Limpa a pilha de descarte
            
            EmbaralharDeck(jogador->deck, jogador->deckSize);
        } else {
            // Não há cartas no deck nem no descarte
            printf("Não há cartas disponíveis para comprar.\n");
            return 0; 
        }
    }
    
    // 3. Comprar a carta (do topo/final do array do deck)
    // Move a carta do topo do deck para o final da mão
    int cartaIndexNoDeck = jogador->deckSize - 1; 

    MoverCartaEntrePilhas(jogador->deck, 
                          &jogador->deckSize, 
                          cartaIndexNoDeck, 
                          jogador->hand, 
                          &jogador->handSize);

    printf("Carta comprada. Deck: %d, Mão: %d\n", jogador->deckSize, jogador->handSize);
    return 1; // 1 carta comprada
}


void resetarEscudo(Entity* entidade){
    if (entidade->escudoAtual > 0)
        entidade->escudoAtual = 0;
}

void resetarQuantidadeElixir(Entity* entidade){

    entidade->qtdElixir = QTD_MAX_ELIXIR;

}

void FinalizarRodada(PLAYER* jogador) {
    printf("\n--- FINALIZANDO RODADA DO JOGADOR ---\n");

    resetarEscudo(&listaInimigos[0]);
    resetarEscudo(&listaInimigos[1]);

    // 1. Mover Mão para Descarte
    while (jogador->handSize > 0) {
        // Mover a primeira carta (índice 0) para o descarte
        MoverCartaEntrePilhas(jogador->hand, 
                              &jogador->handSize, 
                              0, // Sempre move o primeiro
                              jogador->discardPile, 
                              &jogador->discardSize);
    }

    // 2. Turno dos Inimigos
    TurnoDosInimigos(jogador);

    // 3. Reinício do Jogador
    resetarEscudo(&jogador->entidade);
    resetarQuantidadeElixir(&jogador->entidade); // Restaura o elixir (QTD_MAX_ELIXIR)

    // 4. Comprar Nova Mão (5 Cartas)
    printf("Comprando nova mão...\n");
    for (int i = 0; i < 5; i++) {
        ComprarCarta(jogador); // Usa a função que implementamos anteriormente
    }

    // 5. Reiniciar seleções do jogador
    jogador->selectedHandIndex = 0; // Seleciona a primeira carta da nova mão
    jogador->selectedEnemy = -1;
    printf("--- INICIO DA NOVA RODADA DO JOGADOR ---\n");
}



void RecomecarRodada(PLAYER* jogador, Entity* listaDeInimigos){
    listaDeInimigos[1].vidaAtual = 0;
    listaDeInimigos[1].isAlive = 0;

    listaDeInimigos[0].vidaAtual = 0;
    listaDeInimigos[0].isAlive = 0;

    ativosInimigos = 0;

    AddEntity(CreateRandomEntity(800, 175)); // Inimigo 0
    AddEntity(CreateRandomEntity(1000, 175)); // Inimigo 1

    char letras[] = {'A', 'D'};

    PreencherBaralhoComRand(IA_INIMIGA_1,TAM_MAX_MAO,0, letras);
    PreencherBaralhoComRand(IA_INIMIGA_2,TAM_MAX_MAO,0, letras);

    
}
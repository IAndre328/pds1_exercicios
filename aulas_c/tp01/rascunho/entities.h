#ifndef ENTITIES_H
#define ENTITIES_H

#include "deck.h"   // Inclui Card e Coords
#include "constants.h"

// Removemos a definição de Coords daqui, pois já está em deck.h

typedef struct {
    int vidaMax;
    int vidaAtual;
    int escudoMax;
    int escudoAtual;
    int qtdElixir;
    //char sprite[200];
    int isAlive;
    Coords coord;
} Entity;

typedef struct{
    Entity entidade;
    
    // CORREÇÃO CRÍTICA: De Card** para Card[] (Array estático)
    Card deck[TAM_MAX_DECK];     // Deck de compra
    int deckSize;                // Tamanho atual do deck
    
    Card discardPile[TAM_MAX_DECK]; // Pilha de descarte
    int discardSize;
    
    Card hand[TAM_MAX_MAO];      // Mão do jogador
    int handSize;
    
    // Você não está usando pileShop ainda, mas se for usar, ajuste:
    // Card pileShop[TAM_MAX_SHOP_CARDS]; 

    int selectedHandIndex;
    int selectedEnemy;
    
} PLAYER;

// Protótipos de entidades (se houver lógica específica depois)
extern PLAYER Player; // Declaração da variável global definida no .c



#endif
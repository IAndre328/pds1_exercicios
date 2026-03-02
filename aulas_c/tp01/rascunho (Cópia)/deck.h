#ifndef DECK_H
#define DECK_H
#include "constants.h"


// Definição de Coords movida para cá para ser acessível a todos
typedef struct {
    int x;
    int y;
} Coords;

typedef struct {
    int id;
    char tipo;      // 'A' (Ataque), 'D' (Defesa), 'E' (Especial)
    int qtdTipo;    // Valor do efeito (Dano ou Escudo)
    int custo;      // Custo de energia (0 a 3)
    
    //char sprite[200];
    //char descricao[200];
    Coords coord;
    
} Card;

// Funções públicas do baralho
void CriarBaralhoInicial(Card* deckAlvo);

void EmbaralharDeck(Card* deck, int size);

void MoverCartaEntrePilhas(Card* sourceArray, int* sourceSize, int cardIndex, 
                          Card* destArray, int* destSize);

void CriarBaralhoInimigo(Card* deckAlvo);

void PreencherBaralhoComRand(Card* deckAlvo, int limite,int indexQueParou, char* letras);

extern Card IA_INIMIGA_1[TAM_MAX_MAO];
extern Card IA_INIMIGA_2[TAM_MAX_DECK];
extern int Index_IA_INIMIGA;

#endif
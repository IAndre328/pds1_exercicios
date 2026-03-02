#include "entities.h"
#include "deck.h"

void processarCarta(Card* card, int cardIndex, PLAYER* jogador);
void FinalizarRodada(PLAYER* jogador);

void darDano(Card card, Entity* target, int targetIndex, PLAYER* playerState);

int ComprarCarta(PLAYER* jogador);

void RecomecarRodada(PLAYER* jogador, Entity* listaDeInimigos);


#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h> // Para usar 'bool'
#include "deck.h"    // Para a struct Card
#include "entities.h" // Para a struct Entity

typedef struct {
  ALLEGRO_DISPLAY* display;
  ALLEGRO_BITMAP* display_buffer;
  ALLEGRO_FONT* font;
} Renderer;

void FillRenderer(Renderer* renderer);
void RenderGame(Renderer* renderer, PLAYER* playerState);
void ClearRenderer(Renderer* renderer);

// --- Novas Funções (Assinaturas Atualizadas) ---

void RenderBackground(Renderer* renderer);

void RenderDeck(Renderer* renderer, int x_left, int y_top, PLAYER* jogador);

// Agora recebe a struct Card e um booleano para seleção
void RenderCard(const Renderer* renderer, Card card, int x_left, int y_top, bool selected);

// Agora recebe o array de cartas da mão, o tamanho e o índice selecionado
void RenderPlayerHand(Renderer* renderer, Card* hand, int handSize, int selectedIndex);

// Agora recebe o ponteiro para a Entity (Jogador ou Inimigo)
void RenderCreature(const Renderer* renderer, int begin_x, int mid_y, int width, Entity* entity);

// Agora recebe o ponteiro para a Entity
void RenderHealthBar(float x_begin, float x_end, float y_down_left, Entity* entity, ALLEGRO_FONT* font);

void RenderEnemies(Renderer* renderer, int selectedIndex);

void RenderEnergy(Renderer* renderer, int currentEnergy);

void RenderDiscardPile(Renderer* renderer, int x_left, int y_top, int discardSize);


extern int inimigosDesenhdos;

#endif
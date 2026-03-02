 #include "renderer.h"


#include <allegro5/allegro_image.h>

#include <allegro5/allegro_primitives.h>

#include <math.h>

#include <stdio.h>

#include <stdlib.h>


#include "constants.h"

#include "utils.h"

#include "deck.h"

#include "enemies.h"


int inimigosDesenhdos = 0;


void DrawScaledText(ALLEGRO_FONT* font, ALLEGRO_COLOR color, float x, float y,

  float xscale, float yscale, int alignment,

  const char* text) {

  ALLEGRO_TRANSFORM transform;

  al_identity_transform(&transform); // Start with an identity transform

  al_scale_transform(&transform, xscale, yscale); // Apply scaling (e.g., sx=2.0, sy=2.0 for double size)

  al_use_transform(&transform); // Use the transform for subsequent drawing


  al_draw_multiline_text(font, color, x, y, 150, 10, alignment, text);

  // al_draw_text(font, color, x, y, alignment, text);

  al_identity_transform(&transform);

  al_use_transform(&transform); // Use the transform for subsequent drawing

}


void DrawCenteredScaledText(ALLEGRO_FONT* font, ALLEGRO_COLOR color, float x,

  float y, float xscale, float yscale, char* text) {

  DrawScaledText(font, color, x, y, xscale, yscale, ALLEGRO_ALIGN_CENTRE, text);

}


void FillRenderer(Renderer* renderer) {

  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);

  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);


  renderer->display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

  must_init(renderer->display, "display");


  renderer->display_buffer = al_create_bitmap(DISPLAY_BUFFER_WIDTH, DISPLAY_BUFFER_HEIGHT);

  must_init(renderer->display_buffer, "display buffer");

  renderer->font = al_create_builtin_font();

  must_init(renderer->font, "font");

}


void RenderBackground(Renderer* renderer) {

al_clear_to_color(al_map_rgb(0, 0, 0));

}


void RenderDeck(Renderer* renderer, int x_left, int y_top, PLAYER* jogador) {

  // Desenha o deck de compra (quadrado verde)

  al_draw_filled_rectangle(x_left, y_top, x_left + DECK_WIDTH, y_top + DECK_HEIGHT, al_map_rgb(0, 100, 0));

  DrawScaledText(renderer->font, al_map_rgb(255, 255, 255), x_left + DECK_WIDTH / 2, y_top - 30, 1.0, 1.0, ALLEGRO_ALIGN_CENTRE, "Deck");


  char deck_count_text[10];

  snprintf(deck_count_text, sizeof(deck_count_text), "%d", jogador->deckSize);

  DrawCenteredScaledText(renderer->font, al_map_rgb(255, 255, 255),

  x_left + DECK_WIDTH / 2.0, // Centro X do Deck

  y_top + DECK_HEIGHT / 2.0,

  1.0, 1.0, deck_count_text);


  al_draw_rectangle(x_left, y_top, x_left + DECK_WIDTH,

  y_top + DECK_HEIGHT, al_map_rgb(255, 255, 255), 2); // Borda branca

}


// [cite: 70-73] Atualizado para receber Entity* e mostrar vida real

  void RenderHealthBar(float x_begin, float x_end, float y_down_left, Entity* entity, ALLEGRO_FONT* font) {

  // --- BARRA DE ESCUDO: CÁLCULOS E DESENHO ---

  if (entity->escudoAtual > 0) {

  // 1. Definição da Posição Y da Barra de Escudo


  float y_down_shield = y_down_left - HEALTH_BAR_HEIGHT - SHIELD_BAR_OFFSET;

  float bar_width = x_end - x_begin;


  // 2. Cálculo do Preenchimento do Escudo

  // Usamos 'escudoMax' como base para o display (se for > 0), senão usamos um valor padrão.

  float max_shield_display = (entity->escudoMax > 0) ? (float)entity->escudoMax : 50.0f;

  float shield_pct = (float)entity->escudoAtual / max_shield_display;

  // O escudo pode exceder o tamanho da barra, então limitamos visualmente

  if(shield_pct > 1.0f) shield_pct = 1.0f;


  // Fundo da barra de escudo (Preto/Cinza escuro)

  al_draw_filled_rectangle( x_begin - HEALTH_BAR_BACKGROUND_EXTRA,
                            y_down_shield - SHIELD_BAR_HEIGHT - HEALTH_BAR_BACKGROUND_EXTRA,
                            x_end + HEALTH_BAR_BACKGROUND_EXTRA,
                            y_down_shield + SHIELD_BAR_BACKGROUND_EXTRA,
                            al_map_rgb(0, 0, 50)); // Azul escuro

  // Parte preenchida (Escudo atual) - CIANO

  al_draw_filled_rectangle(x_begin, y_down_shield - SHIELD_BAR_HEIGHT,
                          x_begin + (bar_width * shield_pct), y_down_shield,
                          SHIELD_BAR_COLOR);

  // Borda do Escudo

  al_draw_rectangle(x_begin, y_down_shield - SHIELD_BAR_HEIGHT, x_end, y_down_shield,
                     al_map_rgb(255, 255, 255), 2);

  // Texto de Escudo

  char shield_text[10];

  snprintf(shield_text, sizeof(shield_text), "%d", entity->escudoAtual);

  // Posição ajustada (ex: um pouco à esquerda/direita da barra de vida, ou centralizado)

  DrawCenteredScaledText(font, al_map_rgb(0, 255, 255),
                        x_end * 1.22, y_down_shield + SHIELD_BAR_HEIGHT / 2.0f, // À direita da barra
                        0.8, 0.8, shield_text);

  }



  float bar_width = x_end - x_begin;

  float max = (entity->vidaMax > 0) ? (float)entity->vidaMax : 1.0;

  float current_pct = (float)entity->vidaAtual / max;

  if(current_pct < 0) current_pct = 0;


// Fundo da barra

  al_draw_filled_rectangle(x_begin - HEALTH_BAR_BACKGROUND_EXTRA,
                            y_down_left - HEALTH_BAR_HEIGHT - HEALTH_BAR_BACKGROUND_EXTRA,
                            x_end + HEALTH_BAR_BACKGROUND_EXTRA,
                            y_down_left + HEALTH_BAR_BACKGROUND_EXTRA,
                            al_map_rgb(50, 0, 0)); // Vermelho escuro/Cinza


  // Parte preenchida (Vida atual)

  al_draw_filled_rectangle(x_begin, y_down_left - HEALTH_BAR_HEIGHT,
                          x_begin + (bar_width * current_pct), y_down_left,
                          al_map_rgb(255, 0, 0));

  // Borda

  al_draw_rectangle(x_begin, y_down_left - HEALTH_BAR_HEIGHT,
                    x_end, y_down_left, al_map_rgb(255, 255, 255), 2);


  // Texto: Vida Atual / Vida Max (Seu código de texto original)

  char life_text[20];

  snprintf(life_text, sizeof(life_text), "%d/%d", entity->vidaAtual, entity->vidaMax);

  float mid_x = (x_begin + x_end) * 0.417;

  float mid_y = (y_down_left + y_down_left / 2 + HEALTH_BAR_HEIGHT) * 0.494f;

  float escala = 1.2f;


  if (entity->coord.x == Player.entidade.coord.x) mid_y = (y_down_left + y_down_left / 2 + HEALTH_BAR_HEIGHT) * 0.51f;


  // Ajustando a posição do texto de vida para não ficar por cima do texto de escudo

  DrawScaledText(font, al_map_rgb(255, 255, 255), mid_x,
                mid_y, escala, escala, ALLEGRO_ALIGN_CENTER, life_text);

  // Seu texto de escudo original foi movido para o bloco 'if (entity->escudoAtual > 0)' acima.

}



void RenderCreature(const Renderer* renderer, int begin_x, int mid_y, int width, Entity* entity) {

  al_draw_filled_circle(begin_x + width / 2.0, mid_y, width,

  al_map_rgb(255, 255, 255));

  float x_end = begin_x + width;


  float health_bar_y = mid_y + width + 20;

  // Chamada corrigida: Passa a entidade e a fonte

  RenderHealthBar(begin_x, x_end, health_bar_y, entity, renderer->font);


  if (entity->coord.x == listaInimigos[0].coord.x || entity->coord.x == listaInimigos[1].coord.x){


    // --- DESENHO DA PRÓXIMA AÇÃO DO INIMIGO ---

    // Posição para o ícone de ação (ajustado para ficar acima da cabeça/barras)

    int action_icon_x = begin_x;

    // Ajuste a posição Y para ficar visível (acima das barras)

    int action_icon_y = mid_y - width - 60;


    // O texto/símbolo da próxima ação

    char action_text[10];

    ALLEGRO_COLOR action_color;

    Card nextAction = (inimigosDesenhdos % 2 == 0 ? IA_INIMIGA_1[Index_IA_INIMIGA] : IA_INIMIGA_2[Index_IA_INIMIGA]);


    // Verifique o tipo de carta que define a ação

    switch (nextAction.tipo) {

      case 'A': // Ataque

        sprintf(action_text, "ATK %d", nextAction.qtdTipo);

        action_color = al_map_rgb(255, 100, 100); // Vermelho Claro

        break;

      case 'D': // Defesa/Escudo

        sprintf(action_text, "DEF %d", nextAction.qtdTipo);

        action_color = al_map_rgb(100, 200, 255); // Azul Claro

        break;

      case 'E': // Especial

        sprintf(action_text, "SPEC");

        action_color = al_map_rgb(255, 255, 0); // Amarelo

        break;

      default:

      sprintf(action_text, "??");

      action_color = al_map_rgb(255, 255, 255);

      break;

    }

    // Desenha o texto da ação centralizado

    DrawCenteredScaledText(renderer->font, action_color,
                          (float)action_icon_x / 1.46, (float)action_icon_y,
                          1.5f, 1.5f, action_text); // Aumenta a escala para destaque




    }

  
}


// [cite: 83] Cada carta deve ser representada por figura com tipo, custo e efeito

// Cada carta deve ser representada por figura com tipo, custo e efeito
void RenderCard(const Renderer* renderer, Card card, int x_left, int y_top, bool selected) {
  
  // Criação de um bitmap temporário para desenhar a carta
  ALLEGRO_BITMAP* card_bitmap = al_create_bitmap(CARD_WIDTH, CARD_HEIGHT);
  al_set_target_bitmap(card_bitmap);

  // Definição da cor de fundo baseada no tipo da carta
  ALLEGRO_COLOR bg_color;
  if (card.tipo == 'A') bg_color = al_map_rgb(255, 200, 200);      // Ataque
  else if (card.tipo == 'D') bg_color = al_map_rgb(200, 200, 255); // Defesa
  else bg_color = al_map_rgb(200, 255, 200);                       // Especial

  // Desenha o corpo da carta como um retângulo arredondado
  al_draw_filled_rounded_rectangle(0, 0, CARD_WIDTH, CARD_HEIGHT, 5, 5, bg_color);
  
  // Borda (destaca se estiver selecionada)
  ALLEGRO_COLOR border_color = selected ? al_map_rgb(255, 215, 0) : al_map_rgb(0, 0, 0);
  int thickness = selected ? 4 : 2;
  al_draw_rounded_rectangle(0, 0, CARD_WIDTH, CARD_HEIGHT, 5, 5, border_color, thickness);

  // Configuração inicial para o desenho de texto
  float xscale = 1.5, yscale = 1.5; 
  ALLEGRO_COLOR text_color = al_map_rgb(0, 0, 0);
  char text[32];

  // 1. Desenha o Custo (Canto superior esquerdo)
  sprintf(text, "%d", card.custo);
  
  // Desenha um circulo pequeno para o custo
  al_draw_filled_circle(15, 15, 10, al_map_rgb(255, 255, 0)); 
  DrawScaledText(renderer->font, text_color, 8, 8, xscale, yscale, ALLEGRO_ALIGN_LEFT, text);

  // 2. Desenha o Tipo e Valor (Centro)
  xscale = 2.0; yscale = 2.0;
  if (card.tipo == 'A') sprintf(text, "ATK\n%d", card.qtdTipo);
  else if (card.tipo == 'D') sprintf(text, "DEF\n%d", card.qtdTipo);
  else sprintf(text, "ESP");

  DrawScaledText(renderer->font, text_color, CARD_WIDTH/2 - 50, CARD_HEIGHT/3, xscale, yscale, ALLEGRO_ALIGN_LEFT, text);

  // Desenha a carta no buffer principal (display_buffer)
  al_set_target_bitmap(renderer->display_buffer);
  
  // Se selecionado, desloca a carta para cima (efeito visual)
  int draw_y = selected ? y_top - 30 : y_top;
  
  al_draw_scaled_bitmap(card_bitmap, 0, 0, CARD_WIDTH, CARD_HEIGHT, x_left,
                        draw_y, CARD_WIDTH, CARD_HEIGHT, 0);

  // Destrói o bitmap temporário da carta
  al_destroy_bitmap(card_bitmap);
}

// Atualize para receber o vetor de cartas da mão

// Corrigido: Agora aceita os dados da mão para desenhar as cartas

void RenderPlayerHand(Renderer* renderer, Card* hand, int handSize, int selectedIndex) {

int spacing = 10;

int total_width = (CARD_WIDTH + spacing) * handSize;

int start_x = (DISPLAY_BUFFER_WIDTH - total_width) / 2; // Centraliza a mão


for(int i = 0; i < handSize; i++) {

int x = start_x + i * (CARD_WIDTH + spacing);

// Passa 'true' se o índice atual for o selecionado

RenderCard(renderer, hand[i], x, HAND_BEGIN_Y, (i == selectedIndex));

  }

}


void RenderDiscardPile(Renderer* renderer, int x_left, int y_top, int discardSize) {

  // 1. Desenha o fundo da pilha (um retângulo quadrado)

  al_draw_filled_rectangle(x_left, y_top, x_left + DECK_WIDTH,
                          y_top + DECK_HEIGHT, al_map_rgb(150, 0, 0)); // Cor vermelha escura


  // 2. Desenha a borda

  al_draw_rectangle(x_left, y_top, x_left + DECK_WIDTH,
                    y_top + DECK_HEIGHT,
                    al_map_rgb(255, 255, 255), 2); // Borda branca


  // 3. Converte o tamanho do descarte para uma string

  char text[10];

  sprintf(text, "%d", discardSize);


  char textDiscard[] = "DISCARTE";


  // 4. Desenha o texto com a contagem de cartas

  DrawCenteredScaledText(renderer->font, al_map_rgb(255, 255, 255),
                        x_left + DECK_WIDTH / 2, // Centro X
                        y_top + DECK_HEIGHT / 2 - 10, // Centro Y
                        1.0, 1.0, text);

  // 5. Desenha o rótulo "DISCARTE"

  DrawCenteredScaledText(renderer->font, al_map_rgb(255, 255, 255),

  x_left + DECK_WIDTH / 2, // Centro X

  y_top - 30, // Centro Y

  1.0, 1.0, textDiscard);

}


// Função genérica antiga - Limpe as chamadas que exigem dados do jogo (Game State)

void RenderEnemies(Renderer* renderer, int selectedIndex) {

  // Acessa as variáveis globais definidas em enemies.c

  extern Entity listaInimigos[MAX_ENEMIES];

  extern int ativosInimigos;


  for (int i = 0; i < ativosInimigos; i++) {

    // Só desenha se estiver vivo (assumindo que vida <= 0 remove ou marca flag)

    if (listaInimigos[i].vidaAtual > 0) {

      int width = 50; // Tamanho base do inimigo


      // Se este for o inimigo selecionado (seta vermelha ou destaque)

      if (i == selectedIndex) {

        al_draw_circle(listaInimigos[i].coord.x + width/2,

        listaInimigos[i].coord.y,

        width + 5,

        al_map_rgb(255, 50, 50), 3); // Círculo vermelho ao redor

    }


    RenderCreature(renderer, listaInimigos[i].coord.x, listaInimigos[i].coord.y, width, &listaInimigos[i]);
    inimigosDesenhdos++;
    if (inimigosDesenhdos > 1) inimigosDesenhdos = 0;
    }

  }

}


// --- CORREÇÃO 2: Implementar RenderEnergy ---

void RenderEnergy(Renderer* renderer, int currentEnergy) {

  char text[32];

  sprintf(text, "Elixir: %d/%d", currentEnergy, QTD_MAX_ELIXIR);

  float center_x = DISPLAY_BUFFER_WIDTH - 110;

  float center_y = DISPLAY_BUFFER_HEIGHT - 75;

  float radius = 30;

  // Desenha uma bolinha de energia no canto inferior direito

  al_draw_filled_circle(center_x, center_y, radius, al_map_rgb(255, 200, 0));

  // Texto centralizado na bolinha

  DrawCenteredScaledText(renderer->font, al_map_rgb(255, 0, 0),

  center_x, // Centro X

  center_y - 10, // Ajuste -10 para subir o texto

  1.0, 1.0, text); // Reduzi a escala para caber melhor

}


// --- CORREÇÃO 3: Atualizar RenderGame ---

void RenderGame(Renderer* renderer, PLAYER* playerState) {


  al_set_target_bitmap(renderer->display_buffer);

  RenderBackground(renderer);

  // 1. Desenha o Deck (Pilha de Compra)

  RenderDeck(renderer, DRAW_DECK_X, DRAW_DECK_Y, playerState);



  // 2. Desenha a Pilha de Descarte

  RenderDiscardPile(renderer, DISCARD_DECK_X, DISCARD_DECK_Y, playerState->discardSize);

  // Desenha o Jogador

  RenderCreature(renderer, PLAYER_BEGIN_X, PLAYER_BEGIN_Y + PLAYER_RADIUS,

  PLAYER_RADIUS, &playerState->entidade);


  // Desenha a Mão

  RenderPlayerHand(renderer, playerState->hand, playerState->handSize, playerState->selectedHandIndex);


  // 3. Passamos o inimigo selecionado para desenhar o destaque

  RenderEnemies(renderer, playerState->selectedEnemy);


  // 4. Passamos a quantidade de elixir atual

  RenderEnergy(renderer, playerState->entidade.qtdElixir);

  al_set_target_backbuffer(renderer->display);

  al_draw_scaled_bitmap(renderer->display_buffer, 0, 0, DISPLAY_BUFFER_WIDTH,

  DISPLAY_BUFFER_HEIGHT, 0, 0, DISPLAY_WIDTH,

  DISPLAY_HEIGHT, 0);


  al_flip_display();

}


void ClearRenderer(Renderer* renderer) {

  al_destroy_display(renderer->display);

  al_destroy_bitmap(renderer->display_buffer);

  al_destroy_font(renderer->font);

} 
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "renderer.h"
#include "utils.h"
#include "deck.h"
#include "combat.h"
#include "entities.h"
#include "enemies.h"

int cartaSeraZerada = 0;

void gerarVidaMaxima(PLAYER* jogador) {
   
    jogador->entidade.vidaMax = 100 + (rand() % 101);
    jogador->entidade.vidaAtual = jogador->entidade.vidaMax;
    
}

int main() {
  must_init(al_init(), "allegro");
  must_init(al_init_image_addon(), "allegro");
  must_init(al_init_primitives_addon(), "primitives");
  must_init(al_install_keyboard(), "keyboard");

  // --- Inicialização da Semente Aleatória ---
  srand(time(NULL));

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
  must_init(timer, "timer");

  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  must_init(queue, "queue");

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_timer_event_source(timer));
  unsigned char keyboard_keys[ALLEGRO_KEY_MAX];
  ClearKeyboardKeys(keyboard_keys);
  ALLEGRO_EVENT event;

  Renderer renderer;
  FillRenderer(&renderer);
  al_register_event_source(queue, al_get_display_event_source(renderer.display));

  // --- NOVO: SETUP DO ESTADO DO JOGO ---
  
  // 1. Inicializa Player (copia os dados base do entities.c)
  // Certifique-se que o entities.c está correto com as structs fixas
  extern PLAYER Player;
  PLAYER playerState = Player; 

  //gerarVidaMaxima(&playerState);

  // 2. Inicializa o Deck Inicial
  // ATENÇÃO: Verifique se a sua função CriarBaralhoInicial está em deck.c
  CriarBaralhoInicial(playerState.deck);
  playerState.deckSize = TAM_MAX_DECK; 
  
  // 3. Embaralha o Deck
  EmbaralharDeck(playerState.deck, playerState.deckSize);

  // 4. Compra inicial de 5 cartas

  playerState.handSize = 0;

  playerState.selectedHandIndex = -1;
  playerState.selectedEnemy = -1;

  for(int i = 0; i < 5; i++) {
      if (playerState.deckSize > 0) {
        playerState.hand[i] = playerState.deck[playerState.deckSize - 1];
        playerState.deckSize--;
        playerState.handSize++;
      }
  }

 // 5- Inicializa os inimigos
  InitializeEntityList();
  
  

  AddEntity(CreateRandomEntity(800, 175)); // Inimigo 0
  AddEntity(CreateRandomEntity(1000, 175)); // Inimigo 1

  char letras[] = {'A', 'D'};

  PreencherBaralhoComRand(IA_INIMIGA_1,TAM_MAX_MAO,0, letras);
  PreencherBaralhoComRand(IA_INIMIGA_2,TAM_MAX_MAO,0, letras);


  printf("Total de Inimigos Ativos (antes do loop): %d\n", ativosInimigos);

  int done = 0, CartaSendoLancada = 0, CartaAtaqueSendoLancada = 0;

  al_start_timer(timer);
  while (1) {
    al_wait_for_event(queue, &event);
    int redraw = 0;

    switch (event.type) {
      case ALLEGRO_EVENT_TIMER:
        redraw = 1;
        if (keyboard_keys[ALLEGRO_KEY_Q] & GAME_KEY_DOWN) {
          done = 1;
          break;
        }

        // --- NOVO: Usamos o flag GAME_KEY_JUST_PRESSED para garantir 1 execução por toque ---
        if ((keyboard_keys[ALLEGRO_KEY_LEFT] & GAME_KEY_JUST_PRESSED)){
          printf("Esquerda\n");
          if (CartaSendoLancada == 0){
            playerState.selectedHandIndex--;

            if(playerState.selectedHandIndex < 0){
                playerState.selectedHandIndex = 0;
            }
          }

          else if (CartaAtaqueSendoLancada == 1){
            playerState.selectedEnemy--;

            // CORREÇÃO: Se for menor que 0, volta para o último inimigo ativo.
            if(playerState.selectedEnemy < 0){
                playerState.selectedEnemy = ativosInimigos - 1; // Permite a circulação
            }
            printf("Inimigo Selecionado: %d\n", playerState.selectedEnemy);

          }
          //keyboard_keys[ALLEGRO_KEY_LEFT] &= ~GAME_KEY_JUST_PRESSED;

        }


        if ((keyboard_keys[ALLEGRO_KEY_RIGHT] & GAME_KEY_JUST_PRESSED)){
          printf("Direita\n");
          if (CartaSendoLancada == 0){
            playerState.selectedHandIndex++;
            if (playerState.selectedHandIndex >= playerState.handSize){
              playerState.selectedHandIndex = playerState.handSize - 1;
            }
          
          }
          else if(CartaAtaqueSendoLancada == 1){
            playerState.selectedEnemy++;
          if (playerState.selectedEnemy >= ativosInimigos){
            playerState.selectedEnemy = ativosInimigos - 1;
          }
          printf("Inimigo Selecionado: %d\n", playerState.selectedEnemy);
        }

        //Limpa o flag JUST_PRESSED após o processamento
        //keyboard_keys[ALLEGRO_KEY_RIGHT] &= ~GAME_KEY_JUST_PRESSED;

        }

        if (((keyboard_keys[ALLEGRO_KEY_ENTER] & GAME_KEY_JUST_PRESSED) || 
              (keyboard_keys[ALLEGRO_KEY_PAD_ENTER] & GAME_KEY_JUST_PRESSED))){
          
          printf("Cheguei aqui\n");

          if (CartaSendoLancada == 0){ // ESTADO 1: Iniciar o lançamento da carta (primeiro ENTER)
            
            // Verifica se há uma carta selecionada na mão
            if (playerState.selectedHandIndex != -1) {
              
                CartaSendoLancada = 1; // Entra no modo de lançamento
                
                Card CartaASerUsada = playerState.hand[playerState.selectedHandIndex];
            
                // Se a carta for de ataque, entra no modo de seleção de inimigo
                if (CartaASerUsada.tipo == 'A') {
                    CartaAtaqueSendoLancada = 1;
                    
                    // CORREÇÃO: Mantenha o alvo atual (se for válido) ou selecione 0 se for -1
                    if (playerState.selectedEnemy == -1 || playerState.selectedEnemy >= ativosInimigos) {
                        playerState.selectedEnemy = ativosInimigos > 0 ? 0 : -1;
                    }
                    // Se selectedEnemy já for 1, ele é mantido!
                }
                // Se não for de ataque, usa imediatamente (Defesa/Especial)
                else {
                    // Nota: A função processarCarta precisa do ponteiro para o alvo (Entity* alvo).
                    // Como não é ataque, passamos NULL para o alvo por enquanto.
                    processarCarta(&playerState.hand[playerState.selectedHandIndex], playerState.selectedHandIndex, &playerState); 
                    printf("Lancei passivo\n");
                    // Sai do modo de lançamento
                    CartaSendoLancada = 0;
                    playerState.selectedHandIndex = -1;
                    CartaAtaqueSendoLancada = 0;
                }
            }

          } else if (CartaAtaqueSendoLancada == 1){ // ESTADO 2: Confirmar o alvo do ataque (segundo ENTER)

            // CORREÇÃO: Apenas checamos se o índice está dentro dos limites de inimigos ATIVOS.
            if (playerState.selectedEnemy > -1 && playerState.selectedEnemy < ativosInimigos){
              
              
              printf("Lançando ataque no inimigo %d\n", playerState.selectedEnemy);
              
              // Chamamos processarCarta. A lógica de remoção/reajuste de alvo após morte
              // será tratada dentro de combat.c (darDano e processarCarta).
              
              processarCarta(&playerState.hand[playerState.selectedHandIndex], playerState.selectedHandIndex, &playerState);
              
              
              // Sai do modo de lançamento
              CartaSendoLancada = 0;
              playerState.selectedHandIndex = -1;
              CartaAtaqueSendoLancada = 0; 
              playerState.selectedEnemy = -1;
            }

          }
          
        
        }
        
        if ((keyboard_keys[ALLEGRO_KEY_Z] & GAME_KEY_JUST_PRESSED)){
          // Volta a seleção de cartas normais
          CartaAtaqueSendoLancada = 0;
          CartaSendoLancada = 0;
          playerState.selectedEnemy = -1; // Deseleciona o inimigo
          keyboard_keys[ALLEGRO_KEY_Z] &= ~GAME_KEY_JUST_PRESSED;
        }

        // if ((keyboard_keys[ALLEGRO_KEY_C] & GAME_KEY_JUST_PRESSED)){
          
        //   if (playerState.selectedHandIndex != -1){
        //      int index = playerState.selectedHandIndex + 1;

        //       playerState.hand[index].custo = 0;
              
              
              
        //   }

        //   keyboard_keys[ALLEGRO_KEY_C] &= ~GAME_KEY_JUST_PRESSED;
        // }

        if ((keyboard_keys[ALLEGRO_KEY_X] & GAME_KEY_JUST_PRESSED)){
          playerState.entidade.vidaAtual = 1;
          keyboard_keys[ALLEGRO_KEY_C] &= ~GAME_KEY_JUST_PRESSED;
        }

        if ((keyboard_keys[ALLEGRO_KEY_F] & GAME_KEY_JUST_PRESSED)){
          printf("To miando os cara\n");
          SetarVidaDosInimigosPara1();
          keyboard_keys[ALLEGRO_KEY_C] &= ~GAME_KEY_JUST_PRESSED;
        }

        if ((keyboard_keys[ALLEGRO_KEY_ESCAPE] & GAME_KEY_JUST_PRESSED)){
          printf("Finalizando a rodada\n");
          FinalizarRodada(&playerState);
          keyboard_keys[ALLEGRO_KEY_C] &= ~GAME_KEY_JUST_PRESSED;
        }

        if ((keyboard_keys[ALLEGRO_KEY_SPACE] & GAME_KEY_JUST_PRESSED)){
          printf("Gerando novos inimigos\n");
          
          RecomecarRodada(&playerState, listaInimigos);


          keyboard_keys[ALLEGRO_KEY_C] &= ~GAME_KEY_JUST_PRESSED;
        }

        // Limpa todas as teclas
        for(int i = 0; i < ALLEGRO_KEY_MAX; i++) {
          keyboard_keys[i] &= ~GAME_KEY_JUST_PRESSED;
        }

        if (playerState.entidade.vidaAtual <= 0){
          playerState.entidade.vidaAtual = 0;
          playerState.entidade.isAlive = 0;
          done++;
        }

        break;

      case ALLEGRO_EVENT_KEY_DOWN:
        keyboard_keys[event.keyboard.keycode] |= GAME_KEY_DOWN | GAME_KEY_JUST_PRESSED;
        break;
      case ALLEGRO_EVENT_KEY_UP:
        keyboard_keys[event.keyboard.keycode] &= ~(GAME_KEY_DOWN | GAME_KEY_JUST_PRESSED);
        break;
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        done = true;
        break;
    }
    if (done) {
      break;
    }

    // You want to put your combat logic here.
    if (redraw) {
    
      
      // SUBSTITUA POR:
      RenderGame(&renderer, &playerState);
      redraw = 0;
    }
  
  }
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  ClearRenderer(&renderer);
  return 0;
}

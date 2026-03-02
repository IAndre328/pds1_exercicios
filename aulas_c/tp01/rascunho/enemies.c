#include "entities.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h> // Para rand()
#include <string.h> // Para strncpy

Entity listaInimigos[MAX_ENEMIES];
int ativosInimigos;

void InitializeEntityList(){

    ativosInimigos = 0;

}

// --- FUNÇÃO 2: Adiciona Inimigo (Implementação do nosso plano anterior) ---
void AddEntity(Entity newEntity) {
    if (ativosInimigos >= MAX_ENEMIES) {
        printf("ERRO: Nao ha mais espaco para inimigos ativos!\n");
        return;
    }
    
    int index = ativosInimigos;
    
    listaInimigos[index] = newEntity; // Copia a struct completa
    
    ativosInimigos++;// Lembrar de reduzir isso quando o inimigo morrer
    
    printf("Novo inimigo adicionado: (Vida: %d)\n", newEntity.vidaAtual);
}


// --- FUNÇÃO 3: Criar Entidade Inimiga com Valores Aleatórios (Seu objetivo!) ---
Entity CreateRandomEntity(int x, int y) {
    Entity e;

    
    // 1. Geração de Atributos Aleatórios
    
    // Vida (Exemplo: 40 a 60)
    int random_health = 40 + (rand() % 21); // rand() % 21 dá de 0 a 20. Total: 40 a 60
    

    // 2. Preenchimento da Estrutura
    e.coord.x = x;
    e.coord.y = y;
    e.vidaMax = random_health;
    e.vidaAtual = e.vidaMax;
    
    e.escudoMax = e.vidaMax/2; // Ou um valor base para inimigos
    e.escudoAtual = 0; // <--- ISSO DEVE SER 0!
    e.isAlive = 1;
   
    
    
    return e;
}

void AddEnemy(Entity newEnemy){
    if (ativosInimigos >= MAX_ENEMIES){
        printf("Erro, há inimigos demais");
        return;
    }
        
    
    listaInimigos[ativosInimigos] = newEnemy;
    ativosInimigos++;

    
    
}

void RemoveEntityAtIndex(int index) {
    if (index < 0 || index >= ativosInimigos) {
        fprintf(stderr, "Erro: RemoveEntityAtIndex: Indice invalido (%d).\n", index);
        return;
    }

    // Compacta o array, movendo todos os elementos após o índice para uma posição anterior
    for (int i = index; i < ativosInimigos - 1; i++) {
        listaInimigos[i] = listaInimigos[i + 1];
    }
    
    ativosInimigos--; 
    printf("Inimigo no indice %d removido. Total de inimigos ativos: %d\n", index, ativosInimigos);
}

void SetarVidaDosInimigosPara1(){
    if(&listaInimigos[0].vidaAtual != NULL) listaInimigos[0].vidaAtual = 1;
    if(&listaInimigos[1].vidaAtual != NULL) listaInimigos[1].vidaAtual = 1;
}

void TurnoDosInimigos(PLAYER* jogador) {
    printf("\n--- INICIO DO TURNO DOS INIMIGOS ---\n");
    
    
    // 2. Loop para cada inimigo ativo
    for (int i = 0; i < ativosInimigos; i++) {
        Entity* inimigo = &listaInimigos[i];
        
        if (inimigo->isAlive) {
            // Lógica de Ataque Fixo: Causa 5 de dano
            Card cartaInimigo = (i == 0 ? IA_INIMIGA_1[Index_IA_INIMIGA] : IA_INIMIGA_2[Index_IA_INIMIGA]);
            
            

            // Chamamos darDano, mas o alvo é o jogador (entidade)
            // O targetIndex (3º argumento) não é relevante aqui, passamos -1
            // mas precisamos da logica completa de dano (escudo/vida)
            
            // ATENÇÃO: Se darDano está em combat.c, precisamos da versão que funciona com Entity*
            // Como não podemos mudar a assinatura de darDano, criaremos uma função auxiliar simples
            // ou adaptamos a chamada. Vamos usar a versão simples temporariamente:

            if (cartaInimigo.tipo == 'A'){
                printf("O inimigo vai atacar\n");
                int dano = cartaInimigo.qtdTipo;
                if (dano > 0) {
                    if (jogador->entidade.escudoAtual > 0) {
                        if (dano >= jogador->entidade.escudoAtual) {
                            dano -= jogador->entidade.escudoAtual;
                            jogador->entidade.escudoAtual = 0;
                        } else {
                            jogador->entidade.escudoAtual -= dano;
                            dano = 0;
                        }
                    }

                    if (dano > 0) {
                        jogador->entidade.vidaAtual -= dano;
                    }
                }
            }

            if (cartaInimigo.tipo == 'D'){
                printf("O inimigo vai defender\n");
                int defesa = cartaInimigo.qtdTipo;
                if (defesa > 0){
                    int defesaRestante = defesa;
                    
                    if (inimigo->escudoAtual + defesaRestante > inimigo->escudoMax)
                        defesaRestante = inimigo->escudoMax - inimigo->escudoAtual;

                    inimigo->escudoAtual = defesaRestante;
                }
            }
            
            printf("Vida do Jogador: %d | Escudo: %d\n", jogador->entidade.vidaAtual, jogador->entidade.escudoAtual);
            
            // Checagem de Game Over (Opcional, mas importante)
            if (jogador->entidade.vidaAtual <= 0) {
                printf("!!! GAME OVER !!!\n");
                // Aqui você pode adicionar um flag para encerrar o jogo em main.c
            }
        }
    }

    for (int i = 0; i < TAM_MAX_MAO; i++)
    {
        printf("Tipo de carta na posição %d do vetor 1: %c\n", i, IA_INIMIGA_1[i].tipo);
        printf("Tipo de carta na posição %d do vetor 1: %c\n", i, IA_INIMIGA_2[i].tipo);

    }
    

    Index_IA_INIMIGA++;
    if (Index_IA_INIMIGA + 1 == TAM_MAX_MAO) Index_IA_INIMIGA = 0;
    printf("--- FIM DO TURNO DOS INIMIGOS ---\n\n");
}
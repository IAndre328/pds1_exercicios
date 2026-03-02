#include "deck.h"
#include "entities.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> // Para printf se necessário



// Função auxiliar para gerar valores baseados no custo 
int gerarValorCarta(int custo) {
    switch (custo) {
        case 0: return 1 + (rand() % 5);   // 1 a 5
        case 1: return 5 + (rand() % 6);   // 5 a 10
        case 2: return 10 + (rand() % 6);  // 10 a 15
        case 3: return 15 + (rand() % 16); // 15 a 30
        default: return 0;
    }
}

// Função auxiliar para criar uma carta individual
Card criarCarta(char tipo, int custo) {
    Card c;
    c.tipo = tipo;
    c.custo = custo;
    
    // Cartas especiais tem lógica fixa no combat.c, valor não importa tanto, 
    // mas o enunciado diz custo 0 [cite: 21]
    if (tipo == 'E') { 
        c.custo = 0;
        c.qtdTipo = 0; // O efeito é hardcoded: comprar 5 cartas
    } else {
        c.qtdTipo = gerarValorCarta(custo);
    }
    return c;
}



// Implementação do algoritmo de Fisher-Yates para structs de Carta
// Adaptado do seu utils.c para funcionar com Card*
void EmbaralharDeck(Card* deck, int size) {
    if (size > 1) {
        for (int i = 0; i < size - 1; i++) {
            // j é um índice aleatório entre i e o final do array
            int j = i + rand() / (RAND_MAX / (size - i) + 1);
            
            if (j == i) continue;

            Card temp = deck[j];
            deck[j] = deck[i];
            deck[i] = temp;
        }
    }
}

void PreencherBaralhoComRand(Card* deckAlvo, int limite,int indexQueParou, char* letras){
    
     while (indexQueParou < limite)
    {
        char tipo = letras[rand() % strlen(letras)];
        int custo = 0;

        if (tipo != 'E') custo = (rand() % 3) + 1;

        deckAlvo[indexQueParou++] = criarCarta(tipo, custo);
    }
}

// Função Principal de Criação do Deck Inicial
// Assume que o array passado tem tamanho pelo menos 20
void CriarBaralhoInicial(Card* deckAlvo) {
    int i = 0;

    // --- 10 CARTAS DE ATAQUE  ---
    // Requisitos: min 1x C0, 3x C1, 1x C2, 1x C3.
    // As outras 4 preenchemos com custo 1 (balanceado) ou 2.
    deckAlvo[i++] = criarCarta('A', 0); // Obrigatório
    deckAlvo[i++] = criarCarta('A', 1); // Obrigatório
    deckAlvo[i++] = criarCarta('A', 1); // Obrigatório
    deckAlvo[i++] = criarCarta('A', 1); // Obrigatório
    deckAlvo[i++] = criarCarta('A', 2); // Obrigatório
    deckAlvo[i++] = criarCarta('A', 3); // Obrigatório
    // 4 restantes para completar 10
    deckAlvo[i++] = criarCarta('A', 1); 
    deckAlvo[i++] = criarCarta('A', 1);
    deckAlvo[i++] = criarCarta('A', 2);
    deckAlvo[i++] = criarCarta('A', 0);

    // --- 8 CARTAS DE DEFESA  ---
    // Requisitos: min 1x C0, 3x C1, 1x C2, EXATAMENTE 1x C3.
    deckAlvo[i++] = criarCarta('D', 0); // Obrigatório
    deckAlvo[i++] = criarCarta('D', 1); // Obrigatório
    deckAlvo[i++] = criarCarta('D', 1); // Obrigatório
    deckAlvo[i++] = criarCarta('D', 1); // Obrigatório
    deckAlvo[i++] = criarCarta('D', 2); // Obrigatório
    deckAlvo[i++] = criarCarta('D', 3); // Obrigatório (Exatamente 1)
    // 2 restantes para completar 8
    deckAlvo[i++] = criarCarta('D', 1);
    deckAlvo[i++] = criarCarta('D', 2);

    // --- 2 CARTAS ESPECIAIS [cite: 32] ---
    deckAlvo[i++] = criarCarta('E', 0);
    deckAlvo[i++] = criarCarta('E', 0);

    char letras[] = {'A', 'D', 'E'};

    PreencherBaralhoComRand(deckAlvo, TAM_MAX_DECK, i, letras);
    
   
    // Embaralha o deck inicial gerado
    EmbaralharDeck(deckAlvo, TAM_MAX_DECK);
}

void MoverCartaEntrePilhas(Card* sourceArray, int* sourceSize, int cardIndex, 
                          Card* destArray, int* destSize) 
{
    // 1. Verificações de segurança
    if (cardIndex < 0 || cardIndex >= *sourceSize) {
        fprintf(stderr, "Erro: MoverCartaEntrePilhas: Indice de carta invalido (%d).\n", cardIndex);
        return;
    }
    
    // Assumimos que destArray tem espaço (TAM_MAX_DECK é 30, TAM_MAX_MAO é 10. OK.)
    // Se estivéssemos movendo entre decks cheios, precisaria de mais checagem.
    if (*destSize >= TAM_MAX_DECK) { 
        fprintf(stderr, "Erro: MoverCartaEntrePilhas: Pilha de destino cheia.\n");
        return;
    }

    // 2. Copia a carta para a pilha de destino
    destArray[*destSize] = sourceArray[cardIndex];
    (*destSize)++;

    // 3. Remove a carta da pilha de origem (preenchendo o "buraco")
    for (int i = cardIndex; i < *sourceSize - 1; i++) {
        sourceArray[i] = sourceArray[i + 1];
    }
    (*sourceSize)--;
    
    // Ajusta o índice de seleção, se necessário, para evitar selecionar um índice que não existe mais.
    // NOTE: Este ajuste é melhor tratado no main.c ou na função de input.
}


void CriarBaralhoInimigo(Card* deckAlvo) {
    // Escolhe um tamanho aleatório entre 3 e TAM_MAX_DECK_INIMIGO
    // Um deck muito pequeno (1 ou 2) pode ser desinteressante.
    int tamanhoDeck = 3 + (rand() % (TAM_MAX_DECK_INIMIGO - 2)); 
    int i = 0;
    
    // Contadores para garantir um mínimo de variedade
    int numAtaque = 0;
    int numDefesa = 0;

    for (i = 0; i < tamanhoDeck; i++) {
        // Lógica de geração: 
        // 1. Garante pelo menos 1 carta de Ataque e 1 de Defesa.
        // 2. Depois, escolhe aleatoriamente o tipo, favorecendo o tipo menos frequente.
        
        char tipoCarta;
        int custoCarta;

        if (numAtaque == 0) {
            tipoCarta = 'A';
        } else if (numDefesa == 0) {
            tipoCarta = 'D';
        } else {
            // Escolhe o tipo: 60% de chance de pegar o tipo menos representado.
            if (numAtaque < numDefesa && (rand() % 10 < 6)) {
                 tipoCarta = 'A';
            } else if (numDefesa < numAtaque && (rand() % 10 < 6)) {
                 tipoCarta = 'D';
            } else {
                // Se estiverem iguais ou falhou no 60%, escolha 50/50.
                tipoCarta = (rand() % 2 == 0) ? 'A' : 'D';
            }
        }
        
        // Define o custo (para inimigos, podemos simplificar e usar mais cartas de custo 0 ou 1)
        // Custo 0: 40%, Custo 1: 40%, Custo 2: 20%
        int r = rand() % 10;
        if (r < 4) {
            custoCarta = 0;
        } else if (r < 8) {
            custoCarta = 1;
        } else {
            custoCarta = 2;
        }

        // Cria a carta e adiciona ao deck
        deckAlvo[i] = criarCarta(tipoCarta, custoCarta);
        
        if (tipoCarta == 'A') {
            numAtaque++;
        } else if (tipoCarta == 'D') {
            numDefesa++;
        }
    }
    
    // Embaralha o deck do inimigo
    EmbaralharDeck(deckAlvo, tamanhoDeck);
    
    // Retorna o tamanho final do deck
}

// IA DOS INIMIGOS
Card IA_INIMIGA_1[TAM_MAX_MAO];
Card IA_INIMIGA_2[TAM_MAX_DECK];
int Index_IA_INIMIGA = 0;


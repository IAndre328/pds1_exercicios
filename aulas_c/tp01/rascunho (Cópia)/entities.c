#include "entities.h"
#include "constants.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PROPORCAO_ALTURA_ENTIDADES 0.2




PLAYER Player = {

    .entidade = {
        .vidaMax = 100,
        .vidaAtual = 100,
        .escudoMax = 50,
        .escudoAtual = 0,
        .qtdElixir = QTD_MAX_ELIXIR,
        .isAlive = 1,
        //.sprite = "./assets/player.png",
        .coord = {
            .x = (int) DISPLAY_WIDTH * 1 / 10, 
            .y = (int) DISPLAY_HEIGHT * PROPORCAO_ALTURA_ENTIDADES
        }
    }

};




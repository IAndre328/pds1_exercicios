#include "entities.h"
#include "constants.h"

extern Entity listaInimigos[MAX_ENEMIES];
extern int ativosInimigos;

void InitializeEntityList();

void AddEntity(Entity newEntity);

Entity CreateRandomEntity(int x, int y);

void SetarVidaDosInimigosPara1();

void RemoveEntityAtIndex(int index);

void TurnoDosInimigos(PLAYER* jogador);

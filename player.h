#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
  Vector2 size;
  Vector2 position;
  float speed;
  Color color;
} Player;

void initPlayer(Player *player, int playerNumber);
void checkBorder(Player *player);
void playerMovement(Player* player, int keyUp, int keyDown);

#endif

#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

// player struct
typedef struct Player {
    Vector2 size;
    Vector2 position;
    float speed;
    Rectangle rect;
    Color color;
} Player;

// functions
void checkBorder(Player *player, int screenWidth, int screenHeight);
void playerMovement(Player* player, int keyUp, int keyDown);

#endif

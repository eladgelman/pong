#include "raylib.h"
#include "player.h"

void checkBorder(Player *player, int screenWidth, int screenHeight) {
    // make sure players wont go outside game borders
    if (player->position.x < 0) player->position.x = 0;
    if (player->position.x > screenWidth - player->size.x) player->position.x = screenWidth - player->size.x;
        if (player->position.y < 0) player->position.y = 0;
        if (player->position.y > screenHeight - player->size.y) player->position.y = screenHeight - player->size.y;
}

void playerMovement(Player* player, int keyUp, int keyDown) {
    // players movement
    if (IsKeyDown(keyDown)) player->position.y += player->speed * GetFrameTime(); 
    if (IsKeyDown(keyUp)) player->position.y -= player->speed * GetFrameTime(); 
}



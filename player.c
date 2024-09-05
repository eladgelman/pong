#include <stdio.h>
#include "raylib.h"
#include "player.h"

void initPlayer(Player *player, int playerNumber) {
    player->size = (Vector2){10, 50};
    player->speed = 200.0f;
    player->color = BLACK;
    if (playerNumber == 1) {
        player->position = (Vector2){0, (float)(GetScreenHeight() / 2.0f - player->size.y / 2.0f )};
    }
    else if (playerNumber == 2) {
        player->position = (Vector2){ (GetScreenWidth() - player->size.x), (float)(GetScreenHeight() / 2.0f - player->size.y / 2.0f) }; 
    }
    else {
        fprintf(stderr, "Error: playerNumber should be a either '1' or '2'\n");
    }
}

void checkBorder(Player *player) {
    if (player->position.y < 0) player->position.y = 0;
    if (player->position.y > GetScreenHeight() - player->size.y) player->position.y = GetScreenHeight() - player->size.y;
}

void playerMovement(Player* player, int keyUp, int keyDown) {
    if (IsKeyDown(keyDown)) player->position.y += player->speed * GetFrameTime(); 
    if (IsKeyDown(keyUp)) player->position.y -= player->speed * GetFrameTime(); 
}




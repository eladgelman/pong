#include "raylib.h"
#include <stdio.h>
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

void initPlayer(Player *player, int playerNumber,const int screenWidth, const int screenHeight) {
    // create player1 and player2 and set parameters
    player->size = (Vector2){20, 40};
    player->speed = 200.0f;
    player->color = BLACK;
    if (playerNumber == 1) {
        player->position = (Vector2){0, (float)(screenHeight / 2 - player->size.y / 2 )};
    }
    else if (playerNumber == 2) {
        player->position = (Vector2){ (screenWidth - player->size.x), (float)(screenHeight / 2 - player->size.y / 2) }; 
    }
    else {
        fprintf(stderr, "Error: playerNumber should be a either '1' or '2'\n");
    }
}


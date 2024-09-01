#include "raylib.h"

typedef struct Player {
    Vector2 size;
    Vector2 position;
    float speed;
    Rectangle rect;
    Color color;
} Player;

typedef struct Ball {
    Vector2 size;
    Vector2 position;
    float speed;
} Ball;

void checkBorder(Player *player, int screenWidth, int screenHeight) {
    // make sure players wont go outside game borders
    if (player->position.x < 0) player->position.x = 0;
    if (player->position.x > screenWidth - player->size.x) player->position.x = screenWidth - player->size.x;
        if (player->position.y < 0) player->position.y = 0;
        if (player->position.y > screenHeight - player->size.y) player->position.y = screenHeight - player->size.y;
}

void playerMovment(Player* player, int keyUp, int keyDown) {
    // player1 movement
    if (IsKeyDown(keyDown)) player->position.y += player->speed * GetFrameTime(); 
    if (IsKeyDown(keyUp)) player->position.y -= player->speed * GetFrameTime(); 
}


int main() {
    const int screenWidth = 600;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "pong");

    
    // define player1 and player2 and declarion of parameters
    Player player1, player2;
    player1.size = player2.size = (Vector2){20, 40};
    player1.speed = player2.speed = 200.0f;
    player1.color = player2.color = BLACK;
    player1.position = (Vector2){0, (float)(screenHeight / 2)};
    player2.position = (Vector2){ (screenWidth - player2.size.x), (float)(screenHeight / 2) };

    while (!WindowShouldClose()) {

        playerMovment(&player1, KEY_S, KEY_D);
        playerMovment(&player2, KEY_K, KEY_J);
        checkBorder(&player1, screenWidth, screenHeight);
        checkBorder(&player2, screenWidth, screenHeight);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("hello game", screenWidth/2 , screenHeight/2, 15, LIGHTGRAY);
        DrawRectangleV(player1.position, player1.size, player1.color);
        DrawRectangleV(player2.position, player2.size, player2.color);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

#include "raylib.h"
#include "player.h"

typedef struct Ball {
    Vector2 size;
    Vector2 position;
    float speed;
} Ball;

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

        playerMovement(&player1, KEY_S, KEY_D);
        playerMovement(&player2, KEY_K, KEY_J);
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

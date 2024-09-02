#include "raylib.h"
#include "player.h"

typedef struct Ball {
    float radius;
    Vector2 position;
    Vector2 velocity;
    Color color;
    bool active;
} Ball;


int main() {
    const int screenWidth = 600;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "pong");
    
    // define players and initialize them 
    Player player1, player2;
    initPlayer(&player1, 1, screenWidth, screenHeight);
    initPlayer(&player2, 2, screenWidth, screenHeight);

    
    
    Ball ball;
    ball.radius = 5.0f;
    ball.position = (Vector2) {screenWidth / 2, screenHeight / 2};
    ball.velocity = (Vector2) {-100.0f, 50.0f}; // maybe use atan2 make anglechange depend on place of player pad collision
    ball.color = BLACK;

    int player1Scoure = 0;
    int player2Scoure = 0;

    bool collisionplayer1 = false;
    bool collisionplayer2 = false;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        const char *scoure = TextFormat("%d\t:\t%d", player1Scoure, player2Scoure);

        player1.rect = (Rectangle){player1.position.x, player1.position.y, player1.size.x, player1.size.y};
        player2.rect = (Rectangle){player2.position.x, player2.position.y, player2.size.x, player2.size.y};

        playerMovement(&player1, KEY_S, KEY_D);
        playerMovement(&player2, KEY_K, KEY_J);


        float deltaTime = GetFrameTime();
        // ball basic movement
        ball.position.x += ball.velocity.x * deltaTime ;
        ball.position.y += ball.velocity.y * deltaTime;
        if (ball.position.x < ball.radius) {
            ball.velocity.x = -ball.velocity.x;
            player2Scoure += 1;

        }
        if (ball.position.x > screenWidth - ball.radius) {
            ball.velocity.x = -ball.velocity.x;
            player1Scoure += 1;

        }
        if (ball.position.y < ball.radius || ball.position.y > screenHeight - ball.radius) {
            ball.velocity.y = -ball.velocity.y;
        } 

        checkBorder(&player1, screenWidth, screenHeight);
        checkBorder(&player2, screenWidth, screenHeight);

        collisionplayer1 = CheckCollisionCircleRec(ball.position, ball.radius, player1.rect);

        collisionplayer2 = CheckCollisionCircleRec(ball.position, ball.radius, player2.rect);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangleV(player1.position, player1.size, player1.color);
        DrawRectangleV(player2.position, player2.size, player2.color);
        DrawCircleV(ball.position, ball.radius, ball.color);
        DrawText(scoure, (screenWidth - MeasureText(scoure, 15)) / 2, 10, 15, GREEN);

        if (collisionplayer1) {
            DrawText("COLLISION!", GetScreenWidth()/2 - MeasureText("COLLISION!",20), GetScreenHeight()/2, 20 , RED);
        }
        if (collisionplayer2) {
            DrawText("COLLISION!", GetScreenWidth()/2 - MeasureText("COLLISION!",20), GetScreenHeight()/2, 20 , RED);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

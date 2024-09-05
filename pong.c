#include <stdbool.h>
#include "raylib.h"
#include "player.h"
#include "ball.h"
#include "game.h"

int main() {
    const int screenWidth = 600;
    const int screenHeight = 400;

    bool gameON = false;
    Player player1, player2;
    Ball ball;
    int player1Score = 0;
    int player2Score = 0;

    bool scoreDelay = false;
    double scoreTime = 0;
    double delayDuration = 4.0;
    bool drawSec[4] = { false }; 

    InitWindow(screenWidth, screenHeight, "Pong");

    initGame(&ball, &player1, &player2);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (gameON) {
            const char *score = TextFormat("%d\t:\t%d", player1Score, player2Score);
            updateGame(&ball, &player1, &player2, &player1Score, &player2Score, &scoreDelay, &scoreTime, delayDuration, drawSec);
            drawGame(&ball, &player1, &player2, score, drawSec);
        }
        else {
            drawMenu(&gameON);
        }
    }

    CloseWindow();

    return 0;
}


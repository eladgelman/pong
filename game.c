#include "player.h"
#include "ball.h"

void initGame(Ball *ball, Player *player1, Player *player2) {
    initPlayer(player1, 1);
    initPlayer(player2, 2);
    initBall(ball);
}

bool checkCollision(Ball *ball, Player *player) {
    return (ball->position.x - ball->radius < player->position.x + player->size.x && ball->position.x + ball->radius > player->position.x && ball->position.y - ball->radius < player->position.y + player->size.y && ball->position.y + ball->radius > player->position.y);
}

void updateGame(Ball *ball, Player *player1, Player *player2, int *player1Score, int *player2Score, bool *scoreDelay, double *scoreTime, double delayDuration, bool drawSec[4]) {
    checkBorder(player1);
    checkBorder(player2);
    playerMovement(player1, KEY_Z, KEY_X);
    playerMovement(player2, KEY_K, KEY_J); 
    ballMovement(ball, player1Score, player2Score, scoreDelay, scoreTime); 

    if (checkCollision(ball, player1)) {
        reflectBall(ball, player1);
    }
    if (checkCollision(ball, player2)) {
        reflectBall(ball, player2);
    }
    if (*scoreDelay) {
        if (GetTime() - *scoreTime >= delayDuration) {
            initBall(ball);
            *scoreDelay = false;
        }
        else if ((GetTime() - *scoreTime >= 0.0) && (GetTime() - *scoreTime < 0.5)) {
            drawSec[0] = true;
        }
        else if ((GetTime() - *scoreTime >= 1.0) && (GetTime() - *scoreTime < 1.5)) {
            drawSec[1] = true;
        }
        else if ((GetTime() - *scoreTime >= 2.0) && (GetTime() - *scoreTime < 2.5)) {
            drawSec[2] = true;
        }
        else if ((GetTime() - *scoreTime >= 3.0) && (GetTime() - *scoreTime < 3.5)) {
            drawSec[3] = true;
        }
        else {
            drawSec[0] = false;
            drawSec[1] = false;
            drawSec[2] = false;
            drawSec[3] = false;
        }
    }
}


// Drawing
void drawGame(Ball *ball, Player *player1, Player *player2, const char *score, bool drawSec[4]) {
    BeginDrawing();
    ClearBackground(GRAY);
    DrawRectangleV(player1->position, player1->size, player1->color);
    DrawRectangleV(player2->position, player2->size, player2->color);
    if (ball->active) {
        DrawCircleV(ball->position, ball->radius, ball->color);
    }
    else {
        if (drawSec[0]) {
            DrawText("3", (GetScreenWidth() - MeasureText("3", 30)) / 2, GetScreenHeight()/2 - 30, 30, GREEN);
        }
        else if (drawSec[1]) {
            DrawText("2", (GetScreenWidth() - MeasureText("2", 30)) / 2, GetScreenHeight()/2 - 30, 30, GREEN);
        }
        else if (drawSec[2]) {
            DrawText("1", (GetScreenWidth() - MeasureText("1", 30)) / 2, GetScreenHeight()/2 - 30, 30, GREEN);
        }
        else if (drawSec[3]) {
            DrawText("GO!", (GetScreenWidth() - MeasureText("GO!", 30)) / 2, GetScreenHeight()/2 - 30, 30, GREEN);
        }
        else {
        }
    }
    DrawText(score, (GetScreenWidth() - MeasureText(score, 30)) / 2, 10, 30, GREEN);
    EndDrawing();
}

void drawMenu(bool *gameON) {
    BeginDrawing();
    ClearBackground(GRAY);
    DrawText("pong", (GetScreenWidth() - MeasureText("pong", 50))/2, (GetScreenHeight()/2) - 150, 50, PINK);
    DrawText("press <space> to start new game", (GetScreenWidth() - MeasureText("press <space> to start new game", 30))/2, (GetScreenHeight()/2) + 40, 30, PINK);
    DrawText("press <ESC> to exit game", (GetScreenWidth() - MeasureText("press <ESC> to exit game", 30))/2, (GetScreenHeight()/2) + 80, 30, PINK);
    if (IsKeyPressed(KEY_SPACE)) {
        *gameON = true;
    }
    else {
    }
    EndDrawing();
}



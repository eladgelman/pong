#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "player.h"

typedef struct Ball {
    float radius;
    Vector2 position;
    Vector2 velocity;
    Color color;
    bool active;
} Ball;

void initBall(Ball *ball);
void ballMovement(Ball *ball, int *player1Score, int *player2Score, bool *scoreDelay, double *scoreTime);
void reflectBall(Ball *ball, Player *player);

#endif

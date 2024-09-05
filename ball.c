#include "raylib.h"
#include "math.h"
#include "ball.h"

void initBall(Ball *ball) {
    ball->radius = 5.0f;
    ball->position = (Vector2) {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    static bool reverseVelocity = false;
    ball->velocity = (Vector2) {reverseVelocity ?  -3.0f: 3.0f, 0.0f}; // Toggle velocity
    reverseVelocity = !reverseVelocity;
    ball->color = BLACK;
    ball->active = true;
}

void reflectBall(Ball *ball, Player *player) {
    float relativeIntersectY = (player->position.y + (player->size.y / 2)) - ball->position.y;
    float normalizeRelativeIntersectionY = (relativeIntersectY / (player->size.y / 2));
    float bounceAngle = normalizeRelativeIntersectionY * (PI / 4);

    ball->velocity.x = -ball->velocity.x;
    ball->velocity.y = ball->velocity.x * tan(bounceAngle);
}

void onScore(bool *scoreDelay, double *scoreTime) {
    *scoreDelay = true;
    *scoreTime = GetTime();
}

void ballMovement(Ball *ball, int *player1Score, int *player2Score, bool *scoreDelay, double *scoreTime) {
    if (ball->active) {
        ball->position.x += ball->velocity.x;
        ball->position.y += ball->velocity.y;

        if (ball->position.y - ball->radius <= 0 || ball->position.y + ball->radius >= GetScreenHeight()) {
        ball->velocity.y = -ball->velocity.y;
        }

        if (ball->position.x > GetScreenWidth()) {
            ball->active = false;
            (*player1Score)++;
            onScore(scoreDelay, scoreTime);
        }
        if (ball->position.x < 0) {
            ball->active = false;
            (*player2Score)++;
            onScore(scoreDelay, scoreTime);
        }
    }
}



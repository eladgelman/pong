#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "ball.h"

void initGame(Ball *ball, Player *player1, Player *player2);
bool checkCollision(Ball *ball, Player *player);
void updateGame(Ball *ball, Player *player1, Player *player2, int *player1Score, int *player2Score, bool *scoreDelay, double *scoreTime, double delayDuration, bool drawSec[4]);
void drawGame(Ball *ball, Player *player1, Player *player2, const char *score, bool drawSec[4]);
void drawMenu(bool *gameON);

#endif

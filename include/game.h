#ifndef GAME_H
#define GAME_H

#include "external.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Position{
    int8_t x;
    int8_t y;
}pos_t;

void setup(int w, int h);
void play();
void move_ent();
bool can_move(int x, int y);
void update_score();
void check_collision();

#endif // GAME_H

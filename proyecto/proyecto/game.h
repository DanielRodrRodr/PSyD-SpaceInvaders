#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "shield.h"
#include "player.h"
#include "playerShot.h"
#include "swarm.h"
#include "enemyShot.h"
#include "ufo.h"
#include "hiscore.h"
#include "credit.h"
#include "sound.h"

typedef enum { run, pause } game_state_t;

typedef struct {
    game_state_t state;
    Shield     shield[MAX_SHIELDS];
    Player     player;
    PlayerShot playerShot;
    Swarm      swarm;
    EnemyShot  enemyShot;
    Ufo        ufo;
    HiScore    hiScore;
    Credit     credit;
    Sound	   music;
} Game;

void game_init( Game *self );
void game_restart( Game *self );
void game_launch( Game *self );

#endif

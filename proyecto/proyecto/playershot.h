#ifndef PLAYERSHOT_H
#define PLAYERSHOT_H

#include <common_types.h>
#include "sprite.h"
#include "sound.h"
#include "player.h"
#include "ufo.h"
#include "swarm.h"
#include "enemyShot.h"

typedef enum { noPlayerShot, playerShotMovingUp, playerShotExplodingCeiling, playerShotExplodingShield } playerShoot_state_t;

typedef struct {
    playerShoot_state_t state;
    uint8  countDown;
    int16  col;
    int16  row;
    Sprite sprite;
    Sprite explosionSprite;
    Sound  launchSound;
    Player *shooter;
} PlayerShot;

void playerShot_init( PlayerShot *self);
void playerShot_launch( PlayerShot *self, Player *shooter );
void playerShot_update( PlayerShot *self, Shield *shield, Swarm *swarm, EnemyShot *enemyShot, Ufo *ufo );
void playerShot_onUfo( PlayerShot *self, Ufo *ufo );
void playerShot_onSwarm( PlayerShot *self, Swarm *swarm );
void playerShot_onShield( PlayerShot *self, Shield *shield );
void playerShot_onEnemyShot( PlayerShot *self, EnemyShot *enemyShot );

#endif

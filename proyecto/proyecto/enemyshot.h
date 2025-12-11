
#ifndef ENEMYSHOT_H
#define ENEMYSHOT_H

#include <common_types.h>
#include "shield.h"
#include "player.h"
#include "sprite.h"

typedef enum { noEnemyShot, enemyShotMovingDown, enemyShotExplodingFloor, enemyShotExplodingShield, enemyShotExploding } enemyShoot_state_t;

typedef struct {
    enemyShoot_state_t state;
    int8   countDown;
    int16  col;
    int16  row;
    Sprite sprite;
    Sprite explosionSprite;
} EnemyShot;

void enemyShot_init( EnemyShot *self );
void enemyShot_launch( EnemyShot *self, uint16 col, uint16 row );
void enemyShot_update( EnemyShot *self, Shield *shield, Player *player );
void enemyShot_onShield( EnemyShot *self, Shield *shield );
void enemyShot_onPlayer( EnemyShot *self, Player *player );
void enemyShot_hit( EnemyShot *self );

#endif

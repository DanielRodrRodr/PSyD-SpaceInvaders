#ifndef ENEMY_H
#define ENEMY_H

#include <common_types.h>
#include "sprite.h"
#include "sound.h"

typedef enum { alien, metroid, squid } enemy_type_t;

typedef enum { enemyAlive, enemyExploding, enemyDead } enemy_state_t;

typedef struct {
    enemy_state_t state;
    enemy_type_t  type;
    uint8  score;
    int16  col;
    int16  row;
    uint8  spriteSet;
    Sprite sprite[2];
    Sprite explosionSprite;
    Sound  explosionSound;
} Enemy;

void enemy_init( Enemy *self, enemy_type_t type, uint8 spriteSet, uint16 col, uint16 row );
void enemy_launch( Enemy *self ); 
void enemy_left( Enemy *self );
void enemy_right( Enemy *self );
void enemy_down( Enemy *self );
void enemy_hit( Enemy *self );
void enemy_kill( Enemy *self );

#endif

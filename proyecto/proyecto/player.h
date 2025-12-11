#ifndef PLAYER_H
#define PLAYER_H

#include <common_types.h>
#include "sprite.h"
#include "sound.h"
#include "lives.h"
#include "score.h"

typedef enum { playerStopped, playerMovingLeft, playerMovingRight, playerExploding, playerDead } player_state_t;

typedef struct {
    player_state_t state;
    uint8  countDown;
    uint8  times;
    int16  col;
    int16  row;
    Sprite sprite;
    uint8  explosionSpriteSet;
    Sprite explosionSprite[2];
    Sound  explosionSound;
    Lives  lives;
    Score  score;
} Player;

void player_init( Player *self );
void player_lives_draw( Player *self );
void player_score_draw( Player *self );
void player_launch( Player *self );
void player_update( Player *self );
void player_left( Player *self );
void player_right( Player *self );
void player_stop( Player *self );
void player_hit( Player *self );
void player_invaded( Player *self );

#endif

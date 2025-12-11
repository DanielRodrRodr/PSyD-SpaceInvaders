#ifndef UFO_H
#define UFO_H

#include <common_types.h>
#include "sprite.h"
#include "sound.h"

typedef enum { noUfo, ufoMovingLeft, ufoMovingRight, ufoExploding, ufoScoring } ufo_state_t;

typedef struct {
    ufo_state_t state;
    uint8  countDown;
    uint8  score;
    int16  col;
    int16  row;
    Sprite sprite;
    Sprite explosionSprite;
    Sound  launchSound;
    Sound  explosionSound;
} Ufo;

void ufo_init( Ufo *self );
void ufo_launch( Ufo *self );
void ufo_update( Ufo *self );
void ufo_hit( Ufo *self );

#endif

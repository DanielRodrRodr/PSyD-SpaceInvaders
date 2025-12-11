#ifndef SPRITE_H
#define SPRITE_H

#include <common_types.h>

typedef struct {
    uint16 width;
    uint16 height;
    uint8  *pixMap;
} Sprite;

boolean sprite_draw( Sprite *self, uint16 col, uint16 row );
void sprite_clear( Sprite *self, uint16 col, uint16 row );

#endif

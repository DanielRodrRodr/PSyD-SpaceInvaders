#ifndef SHIELD_H
#define SHIELD_H

#include <common_types.h>
#include "sprite.h"

typedef struct {
    int16  col;
    int16  row;
    Sprite sprite;
} Shield;

void shield_init( Shield *self, uint16 col );
void shield_launch( Shield *self );

#endif

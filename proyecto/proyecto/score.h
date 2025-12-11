#ifndef SCORE_H
#define SCORE_H

#include <common_types.h>

typedef struct {
    uint16 value;
    int16  col;
    int16  row;
} Score;

void score_init( Score *self );
void score_launch( Score *self );
void score_update( Score *self, uint16 num );

#endif

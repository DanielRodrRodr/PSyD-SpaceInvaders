#ifndef HISCORE_H
#define HISCORE_H

#include <common_types.h>

typedef struct {
    uint16 value;
    int16  col;
    int16  row;
} HiScore;

void hiScore_init( HiScore *self );
void hiScore_launch( HiScore *self );
void hiScore_update( HiScore *self, uint16 num );

#endif

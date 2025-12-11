#ifndef LIVES_H
#define LIVES_H

#include <common_types.h>

typedef struct {
    int16 value;
    int16 col;
    int16 row;
} Lives;

void lives_init( Lives *self );
void lives_launch( Lives *self );
void lives_update( Lives *self );

#endif

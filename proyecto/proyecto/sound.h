#ifndef SOUND_H
#define SOUND_H

#include <common_types.h>

typedef struct {
    int16 * wav;
} Sound;

void sound_play( Sound *self );
void sound_loop( Sound *self );
void sound_stop( void );
boolean sound_isPlaying( void );

#endif

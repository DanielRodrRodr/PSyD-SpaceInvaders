
#include <lcd.h>
#include "config.h"
#include "score.h"

static void score_draw( Score *self );

void score_init( Score *self )
{
    self->value = 0;
    self->col   = (18+7)*FONT_WIDTH*2;
    self->row   = 0;
}

void score_draw( Score *self )
{
}

void score_launch( Score *self )
{
}

void score_update( Score *self, uint16 num )
{
}


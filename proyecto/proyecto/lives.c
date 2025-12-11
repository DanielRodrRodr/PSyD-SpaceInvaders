#include <lcd.h>
#include "config.h"
#include "lives.h"

static void lives_draw( Lives *self );

void lives_init( Lives *self )
{
    self->value = MAX_LIFES;
    self->col   = (31+7)*FONT_WIDTH*2;
    self->row   = 0;
}

static void lives_draw( Lives *self )
{
}

void lives_launch( Lives *self )
{
}

void lives_update( Lives *self )
{  
}

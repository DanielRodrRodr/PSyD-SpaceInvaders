
#include <segs.h>
#include "config.h"
#include "credit.h"

static void credit_draw( Credit *self );

void credit_init( Credit *self )
{
    self->value = 0;
}

void credit_draw( Credit *self )
{
    segs_putchar( self->value );
}

void credit_launch( Credit *self )
{
    credit_draw( self );
}

void credit_update( Credit *self, uint16 num )
{
    self->value += num;
    credit_draw( self );
}


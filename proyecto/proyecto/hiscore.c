
#include <lcd.h>
#include "config.h"
#include "hiscore.h"
#include <at24c04.h>

static void hiScore_load( HiScore *self );
static void hiScore_store( HiScore *self );
static void hiScore_draw( HiScore *self );

void hiScore_init( HiScore *self )
{
	hiScore_load( self );
    self->col = (1+10)*FONT_WIDTH*2;
    self->row = 0;
}

static void hiScore_draw( HiScore *self )
{
}

void hiScore_launch( HiScore *self )
{
}

void hiScore_update( HiScore *self, uint16 num )
{
}

static void hiScore_load( HiScore *self )
{
}

static void hiScore_store( HiScore *self )
{

	uint8 data_msb, data_lsb;

	data_msb = (uint8)((self->value >> 8) & 0xFF);
	data_lsb = (uint8)((self->value) & 0xFF);

	at24c04_bytewrite( 0, data_lsb );
    at24c04_bytewrite( 1, data_msb );
}

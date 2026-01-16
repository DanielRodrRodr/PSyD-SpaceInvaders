#include "config.h"
#include "sprite.h"

extern uint8 lcd_buffer[];

boolean sprite_draw( Sprite *self, uint16 col, uint16 row )
{
    boolean collision;
    uint16 x, y, spriteIdx, lcdOffset;
      
    collision = FALSE;
    for( y=0, spriteIdx=0, lcdOffset=row*2*GAME_WIDTH+col; y<self->height*2; y++, lcdOffset+=GAME_WIDTH )
        for( x=0; x<self->width; x++, spriteIdx++ )
            if( self->pixMap[spriteIdx] )
            {
                if( lcd_buffer[lcdOffset + x] )
                    collision = TRUE;
                lcd_buffer[lcdOffset + x] = self->pixMap[spriteIdx];
            }
    return collision;
}

void sprite_clear( Sprite *self, uint16 col, uint16 row )
{
    uint16 x, y, spriteIdx, lcdOffset;

    for( y=0, spriteIdx=0, lcdOffset=row*2*GAME_WIDTH+col; y<self->height*2; y++, lcdOffset+=GAME_WIDTH )
    {
        for( x=0; x<self->width; x++, spriteIdx++ )
        {
            if( self->pixMap[spriteIdx] != 0 )
            {
                lcd_buffer[lcdOffset + x] = 0;
            }
        }
    }
}

#include "config.h"
#include "pixmaps.h"
#include "shield.h"
#include "sprite.h"

// Necesitamos acceso al buffer de pantalla para "borrar" píxeles
extern uint8 lcd_buffer[];

void shield_init(Shield *self, uint16 col) {
	self->col = col;
	self->row = SHIELD_ROW;
	self->sprite = (Sprite ) { SHIELD_WIDTH, SHIELD_HEIGHT, shieldPixMap };
	shield_launch(self);
}

void shield_launch(Shield *self) {
	sprite_draw(&self->sprite, self->col, self->row);
}

void shield_hit(Shield *self, uint16 col, uint16 row, uint16 width,
		uint16 height) {
	uint16 r, c;
	uint16 pX, pY;
	uint32 lcdOffset;

	for (r = 0; r < height; r++) {
		pY = row + r;

		if (pY < self->row || pY >= (self->row + SHIELD_HEIGHT))
			continue;

		lcdOffset = pY * 2 * GAME_WIDTH;

		for (c = 0; c < width; c++) {
			pX = col + c;
			if (pX >= self->col && pX < (self->col + SHIELD_WIDTH)) {
				lcd_buffer[lcdOffset + pX] = 0;
			}
		}
	}
}

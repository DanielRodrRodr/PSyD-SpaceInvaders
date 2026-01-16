#include <lcd.h>
#include "config.h"
#include "score.h"

static void score_draw(Score *self);

void score_init(Score *self) {
	self->value = 0;
	self->col = (18 + 7) * FONT_WIDTH * 2;
	self->row = 0;
}

static void score_draw(Score *self) {
	lcd_putint(self->col, self->row, BLACK, self->value);
}

void score_launch(Score *self) {
	score_draw(self);
}

void score_update(Score *self, uint16 num) {
	self->value += num;
	score_draw(self);
}

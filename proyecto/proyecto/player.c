#include "config.h"
#include "pixmaps.h"
#include "wavs.h"
#include "player.h"

static void player_draw(Player *self);
static void player_clear(Player *self);

void player_init(Player *self) {
	self->state = playerStopped;
	self->col = PLAYER_MIN_COL;
	self->row = PLAYER_ROW;
	self->sprite = (Sprite ) { PLAYER_WIDTH, PLAYER_HEIGHT, playerPixMap };
	self->explosionSpriteSet = 0;
	self->explosionSprite[0] = (Sprite ) { PLAYER_WIDTH, PLAYER_HEIGHT,
					playerExplosionPixMap_0 };
	self->explosionSprite[1] = (Sprite ) { PLAYER_WIDTH, PLAYER_HEIGHT,
					playerExplosionPixMap_1 };
	self->explosionSound = (Sound ) { PLAYER_EXPLOSION };
	lives_init(&self->lives);
	score_init(&self->score);
}

static void player_draw(Player *self) {
	switch (self->state) {
	case playerStopped:
	case playerMovingLeft:
	case playerMovingRight:
		sprite_draw(&self->sprite, self->col, self->row);
		break;
	case playerExploding:
		sprite_draw(&self->explosionSprite[self->explosionSpriteSet], self->col,
				self->row);
		break;
	default:
		break;
	}
}

static void player_clear(Player *self) {
	switch (self->state) {
	case playerStopped:
	case playerMovingLeft:
	case playerMovingRight:
		sprite_clear(&self->sprite, self->col, self->row);
		break;
	case playerExploding:
		sprite_clear(&self->explosionSprite[self->explosionSpriteSet],
				self->col, self->row);
		break;
	default:
		break;
	}
}

void player_launch(Player *self) {
	lives_launch(&self->lives);
	score_launch(&self->score);
	player_draw(self);
}

void player_update(Player *self) {
	if (self->state == playerExploding) {
		player_clear(self);
		if (self->countDown > 0) {
			self->countDown--;
			if ((self->countDown % 4) == 0)
				self->explosionSpriteSet = !self->explosionSpriteSet;
			player_draw(self);
		} else if (self->lives.value > 0) {
			self->state = playerStopped;
			self->col = PLAYER_MIN_COL;
			player_draw(self);
		} else
			self->state = playerDead;
	} else if (self->state != playerDead) {

		if (self->state == playerMovingLeft) {
			player_clear(self);
			if ((self->col - PLAYER_ADVANCE_COL)>= PLAYER_MIN_COL )
				self->col -= PLAYER_ADVANCE_COL;
			player_draw(self);
		} else if (self->state == playerMovingRight) {
			player_clear(self);
			if ((self->col + PLAYER_ADVANCE_COL)<= PLAYER_MAX_COL )
				self->col += PLAYER_ADVANCE_COL;
			player_draw(self);
		}
	}
}

void player_left(Player *self) {
	if (self->state != playerExploding && self->state != playerDead)
		self->state = playerMovingLeft;
}

void player_right(Player *self) {
	if (self->state != playerExploding && self->state != playerDead)
		self->state = playerMovingRight;
}

void player_stop(Player *self) {
	if (self->state != playerExploding && self->state != playerDead)
		self->state = playerStopped;
}

void player_hit(Player *self) {
	if (self->state != playerExploding && self->state != playerDead) {
		player_clear(self);
		self->state = playerExploding;
		self->countDown = PLAYER_EXPLODING_TIME / 20;
		lives_update(&self->lives);
		sound_play(&self->explosionSound);
		player_draw(self);
	}
}

void player_invaded(Player *self) {
	player_clear(self);
	self->lives.value = 0;
	lives_launch(&self->lives);
	self->state = playerDead;
}

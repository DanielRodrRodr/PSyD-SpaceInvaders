#include "player.h"
#include "config.h"
#include "pixmaps.h"
#include "wavs.h"

static void player_draw(Player *self);
static void player_clear(Player *self);

void player_init(Player *self) {
  self->state = playerStopped;
  self->col = PLAYER_MIN_COL;
  self->row = PLAYER_ROW;
  self->sprite = (Sprite){PLAYER_WIDTH, PLAYER_HEIGHT, playerPixMap};
  self->explosionSpriteSet = 0;
  self->explosionSprite[0] =
      (Sprite){PLAYER_WIDTH, PLAYER_HEIGHT, playerExplosionPixMap_0};
  self->explosionSprite[1] =
      (Sprite){PLAYER_WIDTH, PLAYER_HEIGHT, playerExplosionPixMap_1};
  self->explosionSound = (Sound){PLAYER_EXPLOSION};
  lives_init(&self->lives);
  score_init(&self->score);
}

static void player_draw(Player *self) {
  sprite_draw(&self->sprite, &self->col, &self->row);
}

static void player_clear(Player *self) {
  sprite_clear(&self->sprite, &self->col, &self->row);
}

void player_launch(Player *self) { player_draw(self); }

void player_update(Player *self) {
  switch (self->state) {
  case playerStopped:
    break;
  case playerMovingLeft:
    self->col -= PLAYER_ADVANCE_COL;
    if (self->col <= PLAYER_MIN_COL)
      self->col = PLAYER_MIN_COL;
    break;
  case playerMovingRight:
    self->col += PLAYER_ADVANCE_COL;
    if (self->col >= PLAYER_MAX_COL)
      ;
    self->col = PLAYER_MAX_COL;
    break;
  case playerExploding:
    self->sprite = self->explosionSprite[self->explosionSpriteSet % 2];
    self->explosionSpriteSet++;
    if (self->lives == 0)
      self->state = playerDead;
    break;
  case playerDead:
    // TODO
    break;
  }

  player_draw(self);
}

void player_left(Player *self) { self->state = playerMovingLeft; }

void player_right(Player *self) { self->state = playerMovingRight; }

void player_stop(Player *self) { self->state = playerStopped; }

void player_hit(Player *self) { self->state = playerExploding; }

void player_invaded(Player *self) { self->state = playerDead; }

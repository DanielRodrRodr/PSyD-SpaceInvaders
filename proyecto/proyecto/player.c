#include "config.h"
#include "pixmaps.h"
#include "wavs.h"
#include "player.h"

static void player_draw( Player *self );
static void player_clear( Player *self );

void player_init( Player *self )
{
    self->state = playerStopped;
    self->col = PLAYER_MIN_COL;
    self->row = PLAYER_ROW;
    self->sprite = (Sprite){ PLAYER_WIDTH, PLAYER_HEIGHT, playerPixMap };
    self->explosionSpriteSet = 0;
    self->explosionSprite[0] = (Sprite){ PLAYER_WIDTH, PLAYER_HEIGHT, playerExplosionPixMap_0 };
    self->explosionSprite[1] = (Sprite){ PLAYER_WIDTH, PLAYER_HEIGHT, playerExplosionPixMap_1 };
    self->explosionSound     = (Sound){ PLAYER_EXPLOSION };
    lives_init( &self->lives );
    score_init( &self->score );
}

static void player_draw( Player *self )
{ 
}

static void player_clear( Player *self )
{
}

void player_launch( Player *self )
{
}

void player_update( Player *self )
{
}

void player_left( Player *self )
{
}

void player_right( Player *self )
{
}

void player_stop( Player *self )
{
}

void player_hit( Player *self )
{
}

void player_invaded( Player *self )
{
}

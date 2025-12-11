
// El alcanzado es el que estalla y suena



#include "config.h"
#include "pixmaps.h"
#include "wavs.h"
#include "playerShot.h"

static void playerShot_draw( PlayerShot *self );
static void playerShot_clear( PlayerShot *self );

void playerShot_init( PlayerShot *self )
{
    self->state           = noPlayerShot;
    self->sprite          = (Sprite){ PLAYERSHOT_WIDTH, PLAYERSHOT_HEIGHT, playerShotPixMap };
    self->explosionSprite = (Sprite){ PLAYERSHOT_EXPLOSION_WIDTH, PLAYERSHOT_EXPLOSION_HEIGHT, playerShotExplosionPixMap };
    self->launchSound     = (Sound){ PLAYERSHOOT_LAUNCH };
}

static void playerShot_draw( PlayerShot *self )
{   
}

static void playerShot_clear( PlayerShot *self )
{   
}

void playerShot_launch( PlayerShot *self, Player *player )
{
}

void playerShot_update( PlayerShot *self, Shield *shield, Swarm *swarm, EnemyShot *enemyShot, Ufo *ufo )
{   
}

void playerShot_onUfo( PlayerShot *self, Ufo *ufo )
{
}

void playerShot_onSwarm( PlayerShot *self, Swarm *swarm )
{
}


void playerShot_onShield( PlayerShot *self, Shield *shield )
{
}

void playerShot_onEnemyShot( PlayerShot *self, EnemyShot *enemyShot )
{
}


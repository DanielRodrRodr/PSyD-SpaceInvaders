#include "config.h"
#include "pixmaps.h"
#include "enemyShot.h"

static void enemyShot_draw( EnemyShot *self );
static void enemyShot_clear( EnemyShot *self );

void enemyShot_init( EnemyShot *self )
{
    self->state           = noEnemyShot;
    self->sprite          = (Sprite){ ENEMYSHOT_WIDTH, ENEMYSHOT_HEIGHT, enemyShotPixMap };
    self->explosionSprite = (Sprite){ ENEMYSHOT_EXPLOSION_WIDTH, ENEMYSHOT_EXPLOSION_HEIGHT, enemyShotExplosionPixMap };
}

static void enemyShot_draw( EnemyShot *self )
{
}

static void enemyShot_clear( EnemyShot *self )
{
  
}

void enemyShot_launch( EnemyShot *self, uint16 col, uint16 row )
{
}

void enemyShot_update( EnemyShot *self, Shield *shield, Player *player )
{
}


void enemyShot_onShield( EnemyShot *self, Shield *shield )
{
}

void enemyShot_onPlayer( EnemyShot *self, Player *player )
{
}

void enemyShot_hit( EnemyShot *self )
{
}

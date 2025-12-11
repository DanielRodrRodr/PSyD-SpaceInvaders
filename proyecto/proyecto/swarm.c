#include <timers.h>
#include "config.h"
#include "random.h"
#include "pixmaps.h"
#include "wavs.h"
#include "swarm.h"

static const enemy_type_t formation[SWARM_YLEN][SWARM_XLEN] =
{
    { squid,    squid,    squid,    squid,    squid   }, 
    { alien,    alien,    alien,    alien,    alien   },
    { alien,    alien,    alien,    alien,    alien   },       
    { metroid,  metroid,  metroid,  metroid,  metroid },
    { metroid,  metroid,  metroid,  metroid,  metroid }

};
    
static const uint8 formationSpriteSet[SWARM_YLEN][SWARM_XLEN] =
{
    { 1, 0, 1, 0, 1 }, 
    { 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },       
    { 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1 }
};

static boolean swarm_findNextAlive( Swarm *self );
static void swarm_moveSound( Swarm *self );
static void swarm_updateLeftFront( Swarm *self );
static void swarm_updateRightFront( Swarm *self );
static void swarm_updateDownFront( Swarm *self );

void swarm_init( Swarm *self )
{
    uint8 x, y;
    Enemy *enemy;
        
    self->state = swarmMovingRight;
    self->toMoveY = 0;
    self->toMoveX = 0;
    for( y=0; y<SWARM_YLEN; y++ )
        for( x=0; x<SWARM_XLEN; x++ )
        {
        	enemy = &self->enemies[y][x];
            enemy_init( enemy, formation[y][x], formationSpriteSet[y][x], SWARM_MIN_COL + x*ENEMY_WIDTH, SWARM_MIN_ROW + y*ENEMY_HEIGHT );
        }
    self->enemiesRemaining = SWARM_YLEN*SWARM_XLEN;
    swarm_updateLeftFront( self );
    swarm_updateRightFront( self );
    swarm_updateDownFront( self );   
    self->stepSound[0] = (Sound){ SWARM_MOVE0 };
    self->stepSound[1] = (Sound){ SWARM_MOVE1 };
    self->stepSound[2] = (Sound){ SWARM_MOVE2 };
    self->stepSound[3] = (Sound){ SWARM_MOVE3 };
}

void swarm_lauch( Swarm *self )
{
}

void swarm_update( Swarm *self, Player *player )
{
}

Enemy *swarm_getShooter( Swarm *self )
{
}

void swarm_hit( Swarm *self, Enemy *enemy )
{
}

static boolean swarm_findNextAlive( Swarm *self )
{   
}

static void swarm_moveSound( Swarm *self )
{
}

static void swarm_updateLeftFront( Swarm *self )
{
}

static void swarm_updateRightFront( Swarm *self )
{
}

static void swarm_updateDownFront( Swarm *self )
{
}

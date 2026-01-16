#ifndef SWARM_H
#define SWARM_H

#include <common_types.h>
#include "config.h"
#include "enemy.h"
#include "player.h"
#include "sound.h"

typedef enum {
	swarmMovingLeft,
	swarmMovingRight,
	swarmMovingDownThenLeft,
	swarmMovingDownThenRight,
	oneEnemyExploding,
	swarmDead
} swarm_state_t;

typedef struct {
	swarm_state_t state;
	swarm_state_t stateBeforeExploding;
	uint8 countDown;
	Enemy enemies[SWARM_YLEN][SWARM_XLEN];
	uint8 enemiesRemaining;
	uint8 toMoveX;
	uint8 toMoveY;
	Enemy *exploding;
	Enemy *leftFront;
	Enemy *rightFront;
	Enemy *downFront;
	Sound stepSound[4];
} Swarm;

void swarm_init(Swarm *self);
void swarm_lauch(Swarm *self);
void swarm_update(Swarm *self, Player *player);
Enemy *swarm_getShooter(Swarm *self);
void swarm_hit(Swarm *self, Enemy *enemy);
Enemy *swarm_checkHit(Swarm *self, uint16 col, uint16 row, uint16 width,
		uint16 height);
#endif

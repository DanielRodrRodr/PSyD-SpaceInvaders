#include <timers.h>
#include "config.h"
#include "random.h"
#include "pixmaps.h"
#include "wavs.h"
#include "swarm.h"

static const enemy_type_t formation[SWARM_YLEN][SWARM_XLEN] = { { squid, squid,
		squid, squid, squid }, { alien, alien, alien, alien, alien }, { alien,
		alien, alien, alien, alien }, { metroid, metroid, metroid, metroid,
		metroid }, { metroid, metroid, metroid, metroid, metroid } };

static const uint8 formationSpriteSet[SWARM_YLEN][SWARM_XLEN] = { { 1, 0, 1, 0,
		1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1,
		0, 1 } };

static boolean swarm_findNextAlive(Swarm *self);
static void swarm_moveSound(Swarm *self);
static void swarm_updateLeftFront(Swarm *self);
static void swarm_updateRightFront(Swarm *self);
static void swarm_updateDownFront(Swarm *self);

void swarm_init(Swarm *self) {
	uint8 x, y;
	Enemy *enemy;

	self->state = swarmMovingRight;
	self->toMoveY = SWARM_YLEN - 1;
	self->toMoveX = 0;

	for (y = 0; y < SWARM_YLEN; y++)
		for (x = 0; x < SWARM_XLEN; x++) {
			enemy = &self->enemies[y][x];
			enemy_init(enemy, formation[y][x], formationSpriteSet[y][x],
					SWARM_MIN_COL + x * ENEMY_WIDTH,
					SWARM_MIN_ROW + y * ENEMY_HEIGHT);
		}
	self->enemiesRemaining = SWARM_YLEN * SWARM_XLEN;
	swarm_updateLeftFront(self);
	swarm_updateRightFront(self);
	swarm_updateDownFront(self);
	self->stepSound[0] = (Sound ) { SWARM_MOVE0 };
	self->stepSound[1] = (Sound ) { SWARM_MOVE1 };
	self->stepSound[2] = (Sound ) { SWARM_MOVE2 };
	self->stepSound[3] = (Sound ) { SWARM_MOVE3 };
}

void swarm_lauch(Swarm *self) {
	uint8 x, y;
	for (y = 0; y < SWARM_YLEN; y++)
		for (x = 0; x < SWARM_XLEN; x++)
			enemy_launch(&self->enemies[y][x]);
}

void swarm_update(Swarm *self, Player *player) {
	Enemy *currentEnemy;
	boolean cycleComplete;

	if (self->enemiesRemaining != 0){

		if (self->downFront->row + ENEMY_HEIGHT >= player->row) {
			player_invaded(player);
		}
		else {
			if (swarm_findNextAlive(self)){

				currentEnemy = &self->enemies[self->toMoveY][self->toMoveX];

				// Movemos al enemigo según el estado del enjambre
				switch (self->state) {
				case swarmMovingRight:
					enemy_right(currentEnemy);
					break;
				case swarmMovingLeft:
					enemy_left(currentEnemy);
					break;
				case swarmMovingDownThenRight:
					enemy_down(currentEnemy);
					break;
				case swarmMovingDownThenLeft:
					enemy_down(currentEnemy);
					break;
				}

				//swarm_moveSound(self);

				self->toMoveX++;
				if (self->toMoveX >= SWARM_XLEN) {
					self->toMoveX = 0;
					if (self->toMoveY == 0) {
						self->toMoveY = SWARM_YLEN - 1;
						cycleComplete = TRUE;
					} else {
						self->toMoveY--;
						cycleComplete = FALSE;
					}
				} else {
					cycleComplete = FALSE;
				}

				if (cycleComplete) {
					switch (self->state) {
					case swarmMovingRight:
						if ((self->rightFront->col + ENEMY_WIDTH + ENEMY_ADVANCE_COL)>= GAME_WIDTH ) {
							self->state = swarmMovingDownThenLeft;
						}
						break;
					case swarmMovingLeft:
						if ((self->leftFront->col - ENEMY_ADVANCE_COL)<= 0 ){
							self->state = swarmMovingDownThenRight;
						}
						break;
					case swarmMovingDownThenRight:
						self->state = swarmMovingRight;
						break;
					case swarmMovingDownThenLeft:
						self->state = swarmMovingLeft;
						break;
					}
				}
			}
		}
	}
}
Enemy *swarm_getShooter(Swarm *self) {
	uint8 col, row;
	if (self->enemiesRemaining == 0)
		return NULL ;

	uint8 attempts = 0;
	do {
		col = random_get() % SWARM_XLEN;
		for (row = SWARM_YLEN; row > 0; row--)
			if (self->enemies[row - 1][col].state == enemyAlive)
				return &self->enemies[row - 1][col];
		attempts++;
	} while (attempts < 20);

	for (col = 0; col < SWARM_XLEN; col++)
		for (row = SWARM_YLEN; row > 0; row--)
			if (self->enemies[row - 1][col].state == enemyAlive)
				return &self->enemies[row - 1][col];

	return NULL ;
}

void swarm_hit(Swarm *self, Enemy *enemy) {
	enemy_hit(enemy);
	self->enemiesRemaining--;

	if (enemy == self->leftFront)
		swarm_updateLeftFront(self);
	if (enemy == self->rightFront)
		swarm_updateRightFront(self);
	if (enemy == self->downFront)
		swarm_updateDownFront(self);
}

static boolean swarm_findNextAlive(Swarm *self) {
	uint8 startX = self->toMoveX;
	uint8 startY = self->toMoveY;

	do {
		if (self->enemies[self->toMoveY][self->toMoveX].state == enemyAlive)
			return TRUE;

		self->toMoveX++;
		if (self->toMoveX >= SWARM_XLEN) {
			self->toMoveX = 0;
			if (self->toMoveY == 0)
				self->toMoveY = SWARM_YLEN - 1;
			else
				self->toMoveY--;
		}

	} while (self->toMoveX != startX || self->toMoveY != startY);

	return FALSE;
}

static void swarm_moveSound(Swarm *self) {
	static uint8 soundIndex = 0;
	sound_play(&self->stepSound[soundIndex]);
	soundIndex = (soundIndex + 1) % 4;
}

static void swarm_updateLeftFront(Swarm *self) {
	uint8 x, y;
	for (x = 0; x < SWARM_XLEN; x++)
		for (y = 0; y < SWARM_YLEN; y++)
			if (self->enemies[y][x].state == enemyAlive) {
				self->leftFront = &self->enemies[y][x];
				return;
			}
}

static void swarm_updateRightFront(Swarm *self) {
	int8 x, y;
	for (x = SWARM_XLEN - 1; x >= 0; x--)
		for (y = 0; y < SWARM_YLEN; y++)
			if (self->enemies[y][x].state == enemyAlive) {
				self->rightFront = &self->enemies[y][x];
				return;
			}
}

static void swarm_updateDownFront( Swarm *self )
{
    int8 x, y;
    for( y = SWARM_YLEN - 1; y >= 0; y-- )
    {
        for( x = 0; x < SWARM_XLEN; x++ )
        {
            if( self->enemies[y][x].state == enemyAlive )
            {
                self->downFront = &self->enemies[y][x];
                return;
            }
        }
    }
}

Enemy *swarm_checkHit( Swarm *self, uint16 col, uint16 row, uint16 width, uint16 height )
{
    uint8 x, y;
    Enemy *enemy;

    for( y = 0; y < SWARM_YLEN; y++ )
        for( x = 0; x < SWARM_XLEN; x++ ) {
            enemy = &self->enemies[y][x];

            if( enemy->state == enemyAlive ) {
                if( col < (enemy->col + ENEMY_WIDTH) &&
                    (col + width) > enemy->col &&
                    row < (enemy->row + ENEMY_HEIGHT) &&
                    (row + height) > enemy->row ){
                    return enemy;
                }
            }
        }
    return NULL;
}

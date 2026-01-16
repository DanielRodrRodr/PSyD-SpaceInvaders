#include "config.h"
#include "pixmaps.h"
#include "wavs.h"
#include "playerShot.h"

static void playerShot_draw(PlayerShot *self);
static void playerShot_clear(PlayerShot *self);

void playerShot_init(PlayerShot *self) {
	self->state = noPlayerShot;
	self->sprite = (Sprite ) { PLAYERSHOT_WIDTH, PLAYERSHOT_HEIGHT,
					playerShotPixMap };
	self->explosionSprite = (Sprite ) { PLAYERSHOT_EXPLOSION_WIDTH,
					PLAYERSHOT_EXPLOSION_HEIGHT, playerShotExplosionPixMap };
	self->launchSound = (Sound ) { PLAYERSHOOT_LAUNCH };
}

static void playerShot_draw(PlayerShot *self) {
	switch (self->state) {
	case playerShotMovingUp:
		sprite_draw(&self->sprite, self->col, self->row);
		break;
	case playerShotExplodingCeiling:
	case playerShotExplodingShield:
		sprite_draw(&self->explosionSprite, self->col, self->row);
		break;
	default:
		break;
	}
}

static void playerShot_clear(PlayerShot *self) {
	switch (self->state) {
	case playerShotMovingUp:
		sprite_clear(&self->sprite, self->col, self->row);
		break;
	case playerShotExplodingCeiling:
	case playerShotExplodingShield:
		sprite_clear(&self->explosionSprite, self->col, self->row);
		break;
	default:
		break;
	}
}

void playerShot_launch(PlayerShot *self, Player *player) {
	if (self->state == noPlayerShot) {
		self->state = playerShotMovingUp;
		self->col = player->col + (PLAYER_WIDTH / 2) - (PLAYERSHOT_WIDTH / 2);
		self->row = player->row - PLAYERSHOT_HEIGHT;
		playerShot_draw(self);
		sound_play(&self->launchSound);
	}
}

void playerShot_update(PlayerShot *self, Shield *shield, Swarm *swarm,
		EnemyShot *enemyShot, Ufo *ufo) {
	int i;
	Enemy *hitEnemy;

	if (self->state == playerShotExplodingCeiling
			|| self->state == playerShotExplodingShield) {
		playerShot_clear(self);
		if (self->countDown > 0) {
			self->countDown--;
			playerShot_draw(self);
		} else
			self->state = noPlayerShot;
	} else if (self->state == playerShotMovingUp) {

		playerShot_clear(self);
		self->row -= PLAYERSHOT_ADVANCE_ROW;

		if (self->row <= PLAYERSHOT_MIN_ROW) {
			self->state = playerShotExplodingCeiling;
			self->countDown = PLAYERSHOT_EXPLODING_TIME / 50;
			playerShot_draw(self);
		} else if (enemyShot->state != noEnemyShot
				&& self->col < (enemyShot->col + ENEMYSHOT_WIDTH)&&
				(self->col + PLAYERSHOT_WIDTH) > enemyShot->col &&
				self->row < (enemyShot->row + ENEMYSHOT_HEIGHT) &&
				(self->row + PLAYERSHOT_HEIGHT) > enemyShot->row ){
				playerShot_onEnemyShot( self, enemyShot );
			}
			else {
				for (i = 0; i < MAX_SHIELDS; i++) {
					if (self->col < (shield[i].col + SHIELD_WIDTH)&&
							(self->col + PLAYERSHOT_WIDTH) > shield[i].col &&
							self->row < (shield[i].row + SHIELD_HEIGHT) &&
							(self->row + PLAYERSHOT_HEIGHT) > shield[i].row ) {
						playerShot_onShield( self, &shield[i] );
						return;
					}
				}

				if (ufo->state != noUfo && self->col < (ufo->col + UFO_WIDTH)&&
						(self->col + PLAYERSHOT_WIDTH) > ufo->col &&
						self->row < (ufo->row + UFO_HEIGHT) &&
						(self->row + PLAYERSHOT_HEIGHT) > ufo->row ) {
					playerShot_onUfo( self, ufo );
				}
				else {
					hitEnemy = swarm_checkHit( swarm, self->col, self->row, PLAYERSHOT_WIDTH, PLAYERSHOT_HEIGHT );

					if( hitEnemy != NULL ) {
						swarm_hit( swarm, hitEnemy );
						playerShot_onSwarm( self, swarm );
					}
					else {
						playerShot_draw( self );}
				}
			}
		}
	}

void playerShot_onUfo(PlayerShot *self, Ufo *ufo) {
	ufo_hit(ufo);
	self->state = noPlayerShot;
}

void playerShot_onSwarm(PlayerShot *self, Swarm *swarm) {
	self->state = noPlayerShot;
}

void playerShot_onShield(PlayerShot *self, Shield *shield) {
	shield_hit(shield, self->col, self->row, PLAYERSHOT_WIDTH,
			PLAYERSHOT_HEIGHT);
	self->state = playerShotExplodingShield;
	self->countDown = PLAYERSHOT_EXPLODING_TIME / 50;
	playerShot_draw(self);
}

void playerShot_onEnemyShot(PlayerShot *self, EnemyShot *enemyShot) {
	enemyShot_hit(enemyShot);
	self->state = noPlayerShot;
}

#ifndef PIXMAPS_H
#define PIXMAPS_H

// Base del jugador

#define PLAYER_WIDTH   (16)               // Anchura del pixmap
#define PLAYER_HEIGHT  (8)                // Altura del pixmap

// Proyectil jugador

#define PLAYERSHOT_WIDTH   (1)            // Anchura del pixmap
#define PLAYERSHOT_HEIGHT  (4)            // Altura del pixmap

#define PLAYERSHOT_EXPLOSION_WIDTH  (8)   // Anchura del pixmap
#define PLAYERSHOT_EXPLOSION_HEIGHT (8)   // Altura del pixmap

// Enemigos

#define ENEMY_WIDTH  (16)                 // Anchura del pixmap
#define ENEMY_HEIGHT (10)                 // Altura del pixmap

// Rayo enemigo

#define ENEMYSHOT_WIDTH   (3)             // Anchura del pixmap
#define ENEMYSHOT_HEIGHT  (7)             // Altura del pixmap

#define ENEMYSHOT_EXPLOSION_WIDTH   (6)   // Anchura del pixmap
#define ENEMYSHOT_EXPLOSION_HEIGHT  (8)   // Altura del pixmap

// UFO

#define UFO_WIDTH   (24)                  // Anchura del pixmap
#define UFO_HEIGHT  (10)                  // Altura del pixmap

// Escudo

#define SHIELD_WIDTH  (22)                // Anchura del pixmap
#define SHIELD_HEIGHT (16)                // Altura del pixmap

// Mapas de pixeles

extern uint8 playerPixMap[];
extern uint8 playerExplosionPixMap_0[];
extern uint8 playerExplosionPixMap_1[];
extern uint8 playerShotPixMap[];
extern uint8 playerShotExplosionPixMap[];
extern uint8 alienPixMap_0[];
extern uint8 alienPixMap_1[];
extern uint8 metroidPixMap_0[];
extern uint8 metroidPixMap_1[];
extern uint8 squidPixMap_0[];
extern uint8 squidPixMap_1[];
extern uint8 enemyExplosionPixMap[];
extern uint8 enemyShotPixMap[];
extern uint8 enemyShotExplosionPixMap[];
extern uint8 ufoPixMap[];
extern uint8 ufoExplosionPixMap[];
extern uint8 shieldPixMap[];

// Macro de detección de solapamiento de pixmaps en una coordenada

#define OVERLAP( a, b, b_len ) ( a >= b && a < b+b_len )

#endif

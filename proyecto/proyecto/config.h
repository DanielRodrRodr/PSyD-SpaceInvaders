#ifndef CONFIG_H
#define CONFIG_H

#include <common_types.h>
#include <lcd.h>
#include "pixmaps.h"

/////////////////////////////////////////////////////////////////////////////
// CONFIGURACION
/////////////////////////////////////////////////////////////////////////////

// Pantalla: 1 px de juego = 4 px del LCD

#define GAME_WIDTH    (LCD_WIDTH/2)
#define GAME_HEIGHT   (LCD_HEIGHT/2)

// Fuentes de texto

#define FONT_WIDTH  (4)
#define FONT_HEIGHT (8)

// Posicionado de elementos

#define PLAYER_ROW         (GAME_HEIGHT - PLAYER_HEIGHT - ENEMYSHOT_EXPLOSION_HEIGHT)    // Fila de pantalla en donde comienza a pintarse el pixmap
#define PLAYER_MIN_COL     (0)                                                           // Primera columna de pantalla en donde puede comenzar a pintarse el pixmap
#define PLAYER_MAX_COL     (GAME_WIDTH - PLAYER_WIDTH)                                   // Ultima columna de pantalla en donde puede comenzar a pintarse el pixmap

#define PLAYERSHOT_MIN_ROW (UFO_ROW)                                                     // Primera fila en donde puede comenzar a pintarse el pixmap
#define PLAYERSHOT_MAX_ROW (PLAYER_ROW - PLAYERSHOT_HEIGHT)                              // Ultima fila en donde puede comenzar a pintarse el pixmap

#define SWARM_MIN_ROW      (FONT_HEIGHT + UFO_HEIGHT)                                    // Primera fila de pantalla en donde puede comenzar a pintarse el enjambre
#define SWARM_MAX_ROW      (PLAYER_ROW - ENEMY_HEIGHT)                                   // Ultima fila de pantalla en donde puede comenzar a pintarse el enjambre
#define SWARM_MIN_COL      (0)                                                           // Primera columna de pantalla en donde puede comenzar a pintarse el enjambre
#define SWARM_MAX_COL      (GAME_WIDTH - ENEMY_WIDTH)                                    // Ultima columna de pantalla en donde puede comenzar a pintarse el enjambre

#define ENEMYSHOT_MAX_ROW  (GAME_HEIGHT - ENEMYSHOT_HEIGHT)                              // Ultima fila de pantalla en donde puede comenzar a pintarse el pixmap

#define ENEMYSHOT_EXPLOSION_MIN_ROW (GAME_HEIGHT - ENEMYSHOT_EXPLOSION_HEIGHT)           // Primera fila de pantalla en donde se pinta el pixmap

#define UFO_ROW            (FONT_HEIGHT)                                                 // Fila de pantalla en donde comienza a pintarse el pixmap
#define UFO_MIN_COL        (0)                                                           // Primera columna de pantalla en donde puede comenzar a pintarse el pixmap
#define UFO_MAX_COL        (GAME_WIDTH - UFO_WIDTH)                                      // Ultima columna de pantalla en donde puede comenzar a pintarse el spite

#define SHIELD_ROW         (PLAYER_ROW - PLAYER_HEIGHT - SHIELD_HEIGHT)                  // Fila de pantalla en donde se pinta el pixmap

// Resolucion temporal del juego

#define TICKS_PER_SEC (100)             // 10 ms por tick

// Periodos de iniciacion de tareas (ms)

#define PLAYER_UPDATE_PERIOD      (20)
#define PLAYERSHOT_UPDATE_PERIOD  (50)

#define SWARM_UPDATE_PERIOD       (20)
   
#define ENEMYSHOT_LAUNCH_PERIOD   (2000)
#define ENEMYSHOT_UPDATE_PERIOD   (50)
#define UFO_LAUNCH_PERIOD         (20000)
#define UFO_UPDATE_PERIOD         (200)
#define KEYS_READ_PERIOD          (50)
#define PBS_READ_PERIOD           (30)

#define TICK_PERIOD               (1000/TICKS_PER_SEC)

// Duración de efectos (ms)

#define PLAYER_EXPLODING_TIME     (500)
#define PLAYERSHOT_EXPLODING_TIME (500)
#define ENEMY_EXPLODING_TIME      (1000)
#define ENEMYSHOT_EXPLODING_TIME  (500)
#define UFO_EXPLODING_TIME        (1000)
#define UFO_SCORING_TIME          (1000)

// Tiempos de espera (ms)

#define GAME_OVER_WAIT_TIME       (2000)
#define LAUNCH_WAIT_TIME          (50)

// Vidas

#define MAX_LIFES (3)

// Numero de shields

#define MAX_SHIELDS (3)

// Razones de avance

#define PLAYER_ADVANCE_COL     (1)
#define ENEMY_ADVANCE_COL      (2)
#define ENEMY_ADVANCE_ROW      (4)
#define PLAYERSHOT_ADVANCE_ROW (2)
#define ENEMYSHOT_ADVANCE_ROW  (1)
#define UFO_ADVANCE_COL        (2)

// Profundidades de perforacion de los disparos

#define PLAYERSHOT_EXPLOSION_DEEP   (2)
#define ENEMYSHOT_EXPLOSION_DEEP    (2)

// Puntuaciones

#define METROID_SCORE (10)
#define ALIEN_SCORE   (20)
#define SQUID_SCORE   (30)

// Enjambre enemigo

#define SWARM_XLEN    (5)                           // Numero de enemigos por fila
#define SWARM_YLEN    (5)                           // Numero de enemigos por columna

#endif

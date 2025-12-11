#ifndef WAVS_H
#define WAVS_H

// Direcciones en donde se encuentran cargados los sonidos tras la ejecucion del comando "script load_wavs.script" */

#define INTRO_MUSIC        ((int16 *)0x0c400000)    /* (0xd0c1c B) / ((2 canales) * (2 B/canal) * (16000 muestras/s) = 13,36 s  */
#define ENEMY_EXPLOSION    ((int16 *)0x0c4dae00)    /* (0x5cb0 B)  / ((2 canales) * (2 B/canal) * (16000 muestras/s) =   371 ms */
#define PLAYER_EXPLOSION   ((int16 *)0x0c4e0b00)    /* (0xc628 B)  / ((2 canales) * (2 B/canal) * (16000 muestras/s) =   793 ms */
#define SWARM_MOVE0        ((int16 *)0x0c4ed200)    /* (0x1670 B)  / ((2 canales) * (2 B/canal) * (16000 muestras/s) =    90 ms */
#define SWARM_MOVE1        ((int16 *)0x0c4ee900)    /* (0x17cc B)  / ((2 canales) * (2 B/canal) * (16000 muestras/s) =    95 ms */
#define SWARM_MOVE2        ((int16 *)0x0c4f0100)    /* (0x1814 B)  / ((2 canales) * (2 B/canal) * (16000 muestras/s) =    96 ms */
#define SWARM_MOVE3        ((int16 *)0x0c4f1a00)    /* (0x1910 B)  / ((2 canales) * (2 B/canal) * (16000 muestras/s) =   100 ms */
#define UFO_LAUNCH         ((int16 *)0x0c4f3400)    /* (0x24950 B) / ((2 canales) * (2 B/canal) * (16000 muestras/s) =  2,34 s  */
#define PLAYERSHOOT_LAUNCH ((int16 *)0x0c517e00)    /* (0x24950 B) / ((2 canales) * (2 B/canal) * (16000 muestras/s) =   307 ms */

#endif

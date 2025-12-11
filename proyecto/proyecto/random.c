#include "random.h"

static uint32 number = 0;

void random_init( uint32 seed )
{
    if( seed != 0xFFFFFFFF )
        number = seed;
}

uint32 random_get( void )
{
	uint8 aux;

	aux  = (number & (1<<31)) >> 31;
	aux ^= (number & (1<<21)) >> 21;
	aux = !aux;
	aux ^= (number & (1<<1))  >> 1;
	aux = !aux;
	aux ^= (number & (1<<0))  >> 0;
	aux = !aux;

	number = (number << 1 ) | aux;
	return number;
}

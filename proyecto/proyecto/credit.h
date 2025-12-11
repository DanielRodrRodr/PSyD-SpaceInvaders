#ifndef CREDIT_H
#define CREDIT_H

#include <common_types.h>

typedef struct {
    uint16 value;
} Credit;

void credit_init( Credit *self );
void credit_launch( Credit *self );
void credit_update( Credit *self, uint16 num );

#endif

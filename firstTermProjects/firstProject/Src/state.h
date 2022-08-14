#ifndef STATE_H
#define STATE_H

#define STATE_define(x) void ST_##x(void)
#define STATE(x) ST_##x

#include <stdio.h>
#include <stdlib.h>
#include "driver.h"




void set_pressure_val(unsigned int x);
void send_pressure_val(unsigned int x);


#endif
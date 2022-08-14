#ifndef SENSOR_H
#define SENSOR_H

#include "state.h"

#include <stdio.h>
void sensor_init();
STATE_define(measure);
STATE_define(idle);
extern void set_pressure_val();


void (*sensor_state)();




#endif
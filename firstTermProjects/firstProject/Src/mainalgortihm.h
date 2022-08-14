#ifndef MAIN_H
#define MAIN_H

#include "state.h"
#include <stdio.h>
#include "stdlib.h"
#include "driver.h"
#include "alarm.h"
#include "sensor.h"
#include "flash.h"
// #pragma GCC optimize ("O0")
STATE_define(initmain);
STATE_define(highPressureDetect);
STATE_define(reading);



extern void (*alarm_state)();
extern void (*sensor_state)();
extern void (*flash_state)();


void (*main_algorithm_state)();









#endif
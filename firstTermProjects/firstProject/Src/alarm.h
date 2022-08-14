#ifndef ALARM_H
#define ALARM_H
#include "state.h"
#include "driver.h"
#include <stdio.h>


void alarm_init();
STATE_define(deactivated);
STATE_define(activated);
void (*alarm_state)();





#endif
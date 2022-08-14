#ifndef FLASH_H
#define FLASH_H

#include <stdio.h>
#include "state.h"


STATE_define(waiting);
STATE_define(store);

void (*flash_state)();





#endif
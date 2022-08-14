#ifndef FLASH_H
#define FLASH_H

#include "flash.h"
#include "state.h"

int pressureValue_flash=0;

STATE_define(waiting){
}

STATE_define(store){
	// printf("Storing pressure val  (%d) in flash \n",pressureValue_flash);
}

#endif
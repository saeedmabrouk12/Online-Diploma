#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "alarm.h"
#include "sensor.h"
#include "state.h"
#include "mainalgortihm.h"
// #pragma GCC optimize ("O0")

extern void (*main_algorithm_state)();



int main (){
	Delay(500);
	GPIO_INITIALIZATION();

	Set_Alarm_actuator(1);
	Delay(500);
	main_algorithm_state=STATE(initmain);
	
	main_algorithm_state();
	main_algorithm_state=STATE(reading);


	while (1)
	{
		
		main_algorithm_state();
		// Delay(5000);
	}

}

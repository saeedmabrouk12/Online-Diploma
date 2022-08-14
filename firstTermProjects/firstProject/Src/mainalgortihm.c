	
#include "mainalgortihm.h"
#include "state.h"


unsigned int pressureVal = 0;
extern unsigned int pressureValue_flash;
void set_pressure_val(unsigned int x){
	pressureVal=x;
}
void send_pressure_val(unsigned int x){
	pressureValue_flash=x;
}

STATE_define(initmain){
sensor_state=STATE (measure);
alarm_state=STATE (deactivated);
flash_state=STATE (waiting);
}

STATE_define(reading){
	sensor_state();
	flash_state=STATE(store);
	flash_state();
	flash_state=STATE(waiting);
	if(pressureVal>20){
		main_algorithm_state=STATE(highPressureDetect);
	}else{
		main_algorithm_state=STATE(reading);
	}
	
}
STATE_define(highPressureDetect){
	alarm_state=STATE(activated);
	alarm_state();
	Delay(30000);
	alarm_state=STATE(deactivated);
	alarm_state();
	sensor_state();
	flash_state=STATE(store);
	flash_state();
	flash_state=STATE(waiting);
	if(pressureVal>20){
		main_algorithm_state=STATE(highPressureDetect);
	}else{
		main_algorithm_state=STATE(reading);
	}

}
#include "sensor.h"

void sensor_init(){
	// printf("Sensor_init_done\n");
	return ;
}
//void ST_measure(void)
STATE_define(measure){
	int pressure = getPressureVal();
	set_pressure_val(pressure);
	// printf("Measured Pressure val from sensor : %d\n",pressure);
	
}
STATE_define(idle){

}
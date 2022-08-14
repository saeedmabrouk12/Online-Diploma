#include "alarm.h"
STATE_define(deactivated){
	Set_Alarm_actuator(1);
		Delay(500);


}
STATE_define(activated){
	Set_Alarm_actuator(0);
		Delay(500);

}
/*
 * Encoder.h
 *
 *  Created on: Dec 25, 2022
 *      Author: moham
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"GPIO_interface.h"
#include"RCC_interface.h"
#include"EXTI_interface.h"
#include"NVIC_interface.h"
#include"STK_interface.h"
#include"AFIO_interface.h"

/**
		 * ============================================================================================
		 *     								### Encoders parameters
		 *=============================================================================================

 **/
typedef struct
{

	u16 resolution;
	u8 Encoder_A_port,Encoder_A_pin,Encoder_B_port,Encoder_B_pin;
	u8 RPM;
	s32 counter , last_counter;
	u32 current_time,last_time;
	float delta_time;
}ENcoder_x;

//
static ENcoder_x Encoder_1;
static ENcoder_x Encoder_2;



	/**
			 * ============================================================================================
			 *     								### Encoders Functions
			 *=============================================================================================

	 **/

	/*
	 * function: determine & configrate the Encoder pins A and B
	 * parameters: `A_port: Encoder_A port     A pin :Encoder_A pin
	 * 				B_port: Encoder_B port     B pin :Encoder_B pin
	 * */

	void Encoder_init(ENcoder_x * Encoder);

	/*
		* function: set resolution of the Encoder
		* parameters: none
		* */
	u16 change_resolution (ENcoder_x * Encoder ,u16 s_resolution);

	/*
		 * function: get the value of the Encoder counter
		 * parameters: `none
		 * return : the counter value
		 * */
	u32 get_counter();

	/*
			 * function: reset counter value
			 * parameters: none
			 * */
	void reset_counter();

	/*
				 * function:increase the Encoder1_counter
				 * parameters: none
				 * */
	void front_forward_ISR();



	/*
					 * function:decrease the Encoder1_counter
					 * parameters: none
					 * */
	void front_backward_ISR();

	/*
					 * function:increase the Encoder2_counter
					 * parameters: none
					 * */
		void back_forward_ISR();



		/*
						 * function:decrease the Encoder2_counter
						 * parameters: none
						 * */
		void back_backward_ISR();

	/*
	 	 	 * function:calculate the RPM of the motors by the Encoder counter value
	 	 	 * parameters: none
	 	 	 * return: the RPM value
			* */

	u32 Encoder_Update();

	/*
		 	 	 * function:calculate the RPM of the motors by the Encoder counter value
		 	 	 * parameters: none
		 	 	 * return: the RPM value
				* */
	u8 Get_Rpm(ENcoder_x * Encoder);



	void print_11(void);
	void print_15(void);

#endif /* ENCODER_H_ */

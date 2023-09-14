/*
 * Encoder.c
 *
 *  Created on: Dec 25, 2022
 *      Author: moham
 */

#include <stdio.h>
#include <stdlib.h>
#include "Encoder.h"
#include "config.h"
#include"GPIO_interface.h"
#include "USART_interface.h" // FOR DEBUGE

/*
	 * function: determine & configrate the Encoder pins A and B
	 * parameters: `A_port: Encoder_A port     A pin :Encoder_A pin
	 * 				B_port: Encoder_B port     B pin :Encoder_B pin
	 * */




//
//
//	u16 resolution;
//	u8 Encoder_A_port,Encoder_A_pin,Encoder_B_port,Encoder_B_pin;
//	u32 RPM;
//	u32 counter , last_counter;
//	u32 current_time,last_time;
//	float delta_time;
//
//
//

	void Encoder_init(ENcoder_x * Encoder)
	{
		Encoder->counter=0;
			// RCC configrations
		MRCC_voidPeripheralClockEnable(RCC_APB2,Encoder->Encoder_A_port);
		MRCC_voidPeripheralClockEnable(RCC_APB2,Encoder->Encoder_B_port);
		// GPIO configrations
		MGPIO_voidSetPinMode(Encoder->Encoder_A_port,Encoder->Encoder_A_pin,GPIO_INPUT_PU_PD);
		MGPIO_voidSetPinValue(Encoder->Encoder_A_port,Encoder->Encoder_A_pin,GPIO_LOW);
		MGPIO_voidSetPinMode(Encoder->Encoder_B_port,Encoder->Encoder_B_pin,GPIO_INPUT_PU_PD);
		MGPIO_voidSetPinValue(Encoder->Encoder_B_port,Encoder->Encoder_B_pin,GPIO_LOW);
		// AFIO configrations
		MAFIO_voidEXTIConfiguration(Encoder->Encoder_A_pin,Encoder->Encoder_A_port);
		MAFIO_voidEXTIConfiguration(Encoder->Encoder_B_pin,Encoder->Encoder_B_port);
		//EXTI configrations
		EXTI_voidSelectTrig(Encoder->Encoder_A_pin,EXTI_BOTH_TRIGGER);
		EXTI_voidControlLine(Encoder->Encoder_A_pin, EXTI_ENABLE);
		EXTI_voidSelectTrig(Encoder->Encoder_B_pin,EXTI_BOTH_TRIGGER);
		EXTI_voidControlLine(Encoder->Encoder_B_pin, EXTI_ENABLE);
		// NVIC Enable EXTI
		NVIC_voidInit();
		NVIC_voidEnableInterrupt(40);  // INT 10----> 15

		if(Encoder->Encoder_A_pin == Encoder_1.Encoder_A_pin){
					EXTI_voidSetCallBack(Encoder->Encoder_A_pin,front_forward_ISR);
					EXTI_voidSetCallBack(Encoder->Encoder_B_pin,front_backward_ISR);
					/*USART_voidmsgstring((u8*)" front       ");
					USART_voidmsgint(Encoder->Encoder_A_pin);
					USART_voidmsgstring((u8*)"       front      B: ");
					USART_voidmsgint(Encoder->Encoder_B_pin);*/


				}else {

					EXTI_voidSetCallBack(Encoder->Encoder_A_pin,back_forward_ISR);
					EXTI_voidSetCallBack(Encoder->Encoder_B_pin,back_backward_ISR);

				}


		//USART_voidmsgstring((u8*)"YES");
	}



	/*
		* function: set resolution of the Encoder
		* parameters: Encoder object
		* 				s_resolution : the new resolution
		* */
	u16 change_resolution (ENcoder_x * Encoder , u16 s_resolution)
	{
	  if(s_resolution>0)
		{
		  Encoder->resolution=s_resolution;
		}

	 return Encoder->resolution;
	}



	/*
		 * function: get the value of the Encoder counter
		 * parameters: `none
		 * return : the counter value
		 * */
	u32 get_counter(ENcoder_x * Encoder)
	{
		return Encoder->counter;
	}




	/*
			 * function: reset counter value
			 * parameters: none
			 * */
	void reset_counter(ENcoder_x * Encoder){
		Encoder->counter=0;
	}




	/*
				 * function:increase the Encoder_counter
				 * parameters: none
				 * */
	void front_forward_ISR()
	{
		u8 a,b;
		a= MGPIO_u8GetPinValue(encoder1_front_port,encoder1_front_pin);
		b=MGPIO_u8GetPinValue(encoder1_back_port,encoder1_back_pin);

			if(a != b)
				Encoder_1.counter++;
			else
				Encoder_1.counter--;

/******************************************DEBUGE************************************************/
			//USART_voidmsgstring((s32*)"front_forward       ");
	}




	/*
					 * function:decrease the Encoder_counter
					 * parameters: none
					 * */
	void front_backward_ISR()
	{
		u8 a,b;
				a= MGPIO_u8GetPinValue(encoder1_front_port,encoder1_front_pin);
				b=MGPIO_u8GetPinValue(encoder1_back_port,encoder1_back_pin);

					if(a == b)
						Encoder_1.counter++;
					else
						Encoder_1.counter--;

/******************************************DEBUGE************************************************/
					//USART_voidmsgstring((s32*)"front_backward       ");
	}




	/*
					 * function:increase the Encoder_counter
					 * parameters: none
					 * */
	void back_forward_ISR()
		{
		u8 a,b;
				a= MGPIO_u8GetPinValue(encoder2_front_port,encoder2_front_pin);
				b=MGPIO_u8GetPinValue(encoder2_back_port,encoder2_back_pin);

					if(a != b)
						Encoder_2.counter++;
					else
						Encoder_2.counter--;

/******************************************DEBUGE************************************************/
					//USART_voidmsgstring((s32*)"back_forward in ISR      ");

				/*	USART_voidmsgint(Encoder_2.counter);
					//USART_voidmsgstring((s32*)"        ");
					USART_voidmsgstring((s32*)"\r\n");*/
		}





		/*
						 * function:decrease the Encoder_counter
						 * parameters: none
						 * */
	void back_backward_ISR()
	{
		u8 a,b;
						a= MGPIO_u8GetPinValue(encoder2_front_port,encoder2_front_pin);
						b=MGPIO_u8GetPinValue(encoder2_back_port,encoder2_back_pin);

							if(a == b)
								Encoder_2.counter++;
							else
								Encoder_2.counter--;
/******************************************DEBUGE************************************************/

		//USART_voidmsgstring((s32*)"back_backward       ");
		/*USART_voidmsgint(Encoder_2.counter);
		//USART_voidmsgstring((s32*)"        ");
		USART_voidmsgstring((s32*)"\r\n");*/

	}







	/*
	 	 	 * function:calculate the RPM of the motors by the Encoder counter value
	 	 	 * parameters: Encoder
	 	 	 * return: the RPM value
			* */
	u8 Get_Rpm(ENcoder_x * Encoder){
		return Encoder->RPM;

	}
	u32 Encoder_Update(ENcoder_x * Encoder)
	{

		Encoder->current_time=Millis();
		Encoder->delta_time=((Encoder->current_time - Encoder->last_time)*1.0)/1000;   // delta in seconds
		Encoder->RPM=(((Encoder->counter-Encoder->last_counter)*1.0)/(Encoder->resolution * Encoder->delta_time))*60;

		//
		Encoder->last_time=Encoder->current_time;
		Encoder->last_counter=Encoder->counter;
		return Encoder->RPM;
	}



/******************************************DEBUGE************************************************/
	/*void print_11(void)
	{
		USART_voidmsgstring((u8*)"INT 11 ON");

	}
	void print_15(void)
	{
		USART_voidmsgstring((u8*)"INT 15 ON");
	}*/

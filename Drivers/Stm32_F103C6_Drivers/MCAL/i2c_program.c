/*
 * I2C_program.c
 *
 *  Created on: Nov 30, 2022
 *      Author: moham
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

volatile I2C_reg *I2Cx; // for selection of I2C1 or I2C2


/*
 * function : generate start bit for the frame (TX oR RX frame)
 * parameter: I2C_Type   I2C 1 or 2
 */
void I2C_generate_start_condition(u8 I2C_Type)
{
	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}
		SET_BIT(I2Cx->CR1, I2C_REG_CR1_START_GEN);

}



/*
 * function : generate start bit for the frame (TX oR RX frame)
 * parameter:  I2C_Type   I2C 1 or 2
 * */
void I2C_generate_stop_condition(u8 I2C_Type)
{
	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}
		SET_BIT(I2Cx->CR1, I2C_REG_CR1_STOP_GEN);

}




/*
 * function : check stop bit from the frame
 * parameter:  I2C_Type   I2C 1 or 2
 * */
void I2C_slave_Check_StopBit(u8 I2C_Type)
{
	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}
		 // for slave rx , with ACK
			while( GET_BIT(I2Cx->SR1, I2C_REG_SR1_STOP_DETECTION_FLAG) == 0);
			{
				/* (READ SR1 then  WRITE CR1 */
					u16 val;
					val = I2Cx->SR1;
					SET_BIT(I2Cx->CR1 , I2C_REG_SR1_SB_FLAG);
			}
}




/*
 * function : select the clock and duty cycle of the I2C
 * parameter : clkspeed : speed of clock
 * 				duty_cycle : select the duty cicle
 *
 * */

static void I2C_clk_init ( u32 clkspeed, u32 duty_cycle)

{			u32 pclk = I2C_PERIPHERAL_CLK_FREQ_30MHZ;
			I2Cx->CR2 |= (pclk );

			/*---------------------------- I2Cx TRISE Configuration --------------------*/
			  /* Configure I2Cx: Rise Time */
			//  hI2C->Instance->TRISE = I2C_RISE_TIME(freqrange, hI2C->Init.ClockSpeed);

				u32 trise;
				if( clkspeed <= 100000)
				{
					trise = pclk +1;
				}else
				{
					trise = (((pclk * 300) / 1000) + 1);
				}

					I2Cx->TRISE  &= ~(0x3F);
					I2Cx->TRISE  |= trise;


								// CCR calculation //

					u32 ccr;

						if(clkspeed <= 100000)
						{
							/* configure ccr for standard mode */
							ccr = ( pclk * 1000000) / (clkspeed << 1);

						}else
						{
							 if(duty_cycle == I2C_FM_DUTY_2)
							 {
								 ccr = ( pclk * 1000000)/(3 * clkspeed);
								
							 }else if(duty_cycle == I2C_FM_DUTY_16BY9)
							 {
								 /* this is to reach 400khz in fm mode */
								ccr = ( pclk * 1000000)/(25 * clkspeed);
							 }

						}

						I2Cx->CCR |= ccr;



							 // set mode of speed //
			if( clkspeed <= 100000)
			{     // select the standard or fast mode
				if (I2C_ENABLE_SM == I2C_ENABLE_FM)
					{
						SET_BIT(I2Cx->CCR, I2C_REG_CCR_ENABLE_FM);
					}
					else
					{
						CLR_BIT(I2Cx->CCR, I2C_REG_CCR_ENABLE_FM);
					}
			}else
			{		// select the standard or fast mode
					if (I2C_ENABLE_FM == I2C_ENABLE_FM)
							{
								SET_BIT(I2Cx->CCR, I2C_REG_CCR_ENABLE_FM);
							}
							else
							{
								CLR_BIT(I2Cx->CCR, I2C_REG_CCR_ENABLE_FM);
							}

					// select the duty cycle mode in FM
					if(duty_cycle == I2C_FM_DUTY_16BY9 )
					{
				      SET_BIT(I2Cx->CCR,I2C_REG_CCR_DUTY);
					}else
					{
						 CLR_BIT(I2Cx->CCR,I2C_REG_CCR_DUTY);
					}
			}

}




/*
 * function : initialize the configuration of the I2C type
 * parameter: I2C_Type : I2C 1   or I2C 2
 * 			  I2C_clock : select the clock of the I2C
 * 			  OwnAddress1: set the address of the micro_controller (if master or slave )
 * */
void I2C_init(u8 I2C_Type,u32 I2C_CLOCK, u16 OwnAddress1)
{

	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
			/* GPIO init */
			GPIO_voidSetPinMode(GPIO_PORTB,6,GPIO_PIN_MODE_AF_OD_50MHZ); /* configure PB6 and PB7 as alt. func. open drain */
			GPIO_voidSetPinMode(GPIO_PORTB,7,GPIO_PIN_MODE_AF_OD_50MHZ); /* configure PB6 and PB7 as alt. func. open drain */
			// select the address mode ( 7 bit or 10 bit )
			if(I2C1_ADDRESSING == I2C_ADDRMODE_10BI)
					SET_BIT(I2Cx->OAR1, I2C_REG_OAR1_ADDRMODE);
				else
					CLR_BIT(I2Cx->OAR1, I2C_REG_OAR1_ADDRMODE);

		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
			GPIO_voidSetPinMode(GPIO_PORTB,10,GPIO_PIN_MODE_AF_OD_50MHZ); /* configure PB10 and PB11 as alt. func. open drain */
			GPIO_voidSetPinMode(GPIO_PORTB,11,GPIO_PIN_MODE_AF_OD_50MHZ); /* configure PB10 and PB11 as alt. func. open drain */
				// select the address mode ( 7 bit or 10 bit )
			if(I2C1_ADDRESSING == I2C_ADDRMODE_10BI)
								SET_BIT(I2Cx->OAR1, I2C_REG_OAR1_ADDRMODE);
							else
								CLR_BIT(I2Cx->OAR1, I2C_REG_OAR1_ADDRMODE);
		}


			// disable the I2C prepheral to set the configration
			CLR_BIT(I2Cx->CR1, I2C_REG_CR1_ENABLE_I2C);
			// determine the SM or FM with freq by CCR
			I2C_clk_init( I2C_CLOCK,I2C_FM_DUTY_2);

			// set addressing mode
			if(I2C1_ADDRESSING == I2C_ADDRMODE_10BI)
					SET_BIT(I2Cx->OAR1, I2C_REG_OAR1_ADDRMODE);
				else
					CLR_BIT(I2Cx->OAR1, I2C_REG_OAR1_ADDRMODE);

			// enable the ACK bit
			SET_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);
			// enable scratch time
			CLR_BIT(I2Cx->CR1,I2C_REG_CR1_NOSTRETCH);

			// set address
				I2Cx->OAR1 &= ~( 0x7f << 1);
				I2Cx->OAR1 |=  (OwnAddress1 << 1);

		  // Enable prepheral
				SET_BIT(I2Cx->CR1, I2C_REG_CR1_ENABLE_I2C);



}


/*
 * function : send data from master to slave
 * parameter:	I2C_Type : I2C 1   or I2C 2
 * 			  	address : select the address of the slave to send data to
 * 			  	data: data to be sent
 * 			  	len: length of the data
 * */
void I2C_Mastersend(u8 I2C_Type,u8 address,u8* data,u8 len)
{
		// select the I2C type
	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}

	/* Disable Pos */
		CLR_BIT(I2Cx->CR1, I2C_REG_CR1_POS);

		// enable ACK
		SET_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);
		// generate start bit
		I2C_generate_start_condition(I2C_Type);
		//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
		while(!GET_BIT(I2Cx->SR1 , I2C_REG_SR1_SB_FLAG ));

		//clear sb flag and set the address to the DR register
		if(address == I2C_ADDREES_READ)
			{
				address = ((address << 1) | 0x1); /* addr+Read(1) */
			}
			else
			{
				address = (address << 1);  /* addr+Write(0) */
			}

			I2Cx->DR = address;

			//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
			while (!GET_BIT(I2Cx->SR1 , I2C_REG_SR1_ADDR_SENT_FLAG ));

			//clear address flag
			u16 val;

				val = I2Cx->SR1;
				val = I2Cx->SR2;

								// store data in the data variable//

				u8 size = len; /* reused in onther state */

					while(size>0)
					{
						u32 timeout = 0;
						while( ( GET_BIT(I2Cx->SR1, I2C_REG_SR1_TXE_FLAG) == 0 ) && ( timeout < 100000 ) ) { timeout++; } /* wait TXE =1*/
						I2Cx->DR = data[len - size];
						size--;
						if(( GET_BIT(I2Cx->SR1,I2C_REG_SR1_BTF_FLAG) == 0 ) && ( size != 0 ) )//BTF
						{
							I2Cx->DR = data[len - size];
							size--;
						}
						timeout = 0;
						while( ( GET_BIT(I2Cx->SR1,I2C_REG_SR1_BTF_FLAG) == 0 ) && ( timeout < 100000 ) ) { timeout++; } //wait BTF (data send)
					}

}





/*
 * function : receive data from a selected slave
 * parameter:  I2C_Type : I2C 1   or I2C 2
 * 			   address : select the address of the slave to receive data from
 * 			   pdata: data to be receive
 * 			   len: length of the data
 * */
void I2C_Masterrecive(u8 I2C_Type, u16 address, u8 *pData, u8 len)
{

	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}

				/* Disable Pos */
			CLR_BIT(I2Cx->CR1, I2C_REG_CR1_POS);

			// enable ACK
			SET_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

			/* Prepare transfer parameters */
				u8* pBuffPtr    = pData;
				u8 XferCount   = len;
				u8 XferSize    = XferCount;

				//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
				while(!GET_BIT(I2Cx->SR1 , I2C_REG_SR1_SB_FLAG ));

				//clear sb flag and set the address to the DR register
				if(address == I2C_ADDREES_READ)
					{
						address = ((address << 1) | 0x1); /* addr+Read(1) */
					}
					else
					{
						address = (address << 1);  /* addr+Write(0) */
					}

					I2Cx->DR = address;

					//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
					while (!GET_BIT(I2Cx->SR1 , I2C_REG_SR1_ADDR_SENT_FLAG ));




					/* ---------- Start Read Data -------------------- */


		if (XferSize == 0U)
		{
			/* Clear ADDR flag */
			u16 val;

				val = I2Cx->SR1;
				val = I2Cx->SR2;

			/* Generate Stop */
			I2C_generate_stop_condition(I2C_Type);

		}
		else if (XferSize == 1U)
		{
			/* Disable Acknowledge */
			CLR_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

			/* Clear ADDR flag */
			u16 val;

				val = I2Cx->SR1;
				val = I2Cx->SR2;

			/* Generate Stop */
			I2C_generate_stop_condition(I2C_Type);

		}
		else if (XferSize == 2U)
		{
			/* Enable Pos */
			SET_BIT(I2Cx->CR1, I2C_REG_CR1_POS);

			/* Clear ADDR flag */
			u16 val;

					val = I2Cx->SR1;
					val = I2Cx->SR2;

			/* Disable Acknowledge */
				CLR_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

		}
		else
		{ /* XferSize > 2U */

			/* Enable Acknowledge */
			SET_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

			/* Clear ADDR flag */
			u16 val;

				val = I2Cx->SR1;
				val = I2Cx->SR2;
		}

		while (XferSize > 0U)
		{
			if (XferSize <= 3U)
			{
				/* One byte */
				if (XferSize == 1U)
				{
					/* Wait until RXNE flag is set */
					while ( GET_BIT(I2Cx->SR1,I2C_REG_SR1_RXNE_FLAG) == 0 );


					/* Read data from DR */
					*pBuffPtr = (u8)I2Cx->DR;

					/* Increment Buffer pointer */
					pBuffPtr++;

					/* Update counter */
					XferSize--;
					XferCount--;
				}
				/* Two bytes */
				else if (XferSize == 2U)
				{
					/* Wait until BTF flag is set */
					 while (GET_BIT(I2Cx->SR1,I2C_REG_SR1_BTF_FLAG) != 1);

					/* Generate Stop */
					I2C_generate_stop_condition(I2C_Type);

					/* Read data from DR */
					*pBuffPtr = (u8)I2Cx->DR;

					/* Increment Buffer pointer */
					pBuffPtr++;

					/* Update counter */
					XferSize--;
					XferCount--;

					/* Read data from DR */
					*pBuffPtr = (u8)I2Cx->DR;

					/* Increment Buffer pointer */
					pBuffPtr++;

					/* Update counter */
					XferSize--;
					XferCount--;
				}
				/* 3 Last bytes */
				else
				{
					/* Wait until BTF flag is set */
					u32 timeout=0;
				  while( ( GET_BIT(I2Cx->SR1,I2C_REG_SR1_BTF_FLAG) == 0 ) && ( timeout < 100000 ) ) { timeout++; }

					/* Disable Acknowledge */
				  CLR_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

					/* Read data from DR */
					*pBuffPtr = (u8)I2Cx->DR;

					/* Increment Buffer pointer */
					pBuffPtr++;

					/* Update counter */
					XferSize--;
					XferCount--;

					timeout=0;
					/* Wait until BTF flag is set */
					while( ( GET_BIT(I2Cx->SR1,I2C_REG_SR1_BTF_FLAG) == 0 ) && ( timeout < 100000 ) ) { timeout++; }

					/* Generate Stop */
					SET_BIT(I2Cx->CR1, 9);

					/* Read data from DR */
					*pBuffPtr = (u8)I2Cx->DR;

					/* Increment Buffer pointer */
					pBuffPtr++;

					/* Update counter */
					XferSize--;
					XferCount--;

					/* Read data from DR */
					*pBuffPtr = (u8)I2Cx->DR;

					/* Increment Buffer pointer */
					pBuffPtr++;

					/* Update counter */
					XferSize--;
					XferCount--;
				}
			}
			else /* XferSize > 3*/
			{
				/* Wait until RXNE flag is set */
				 while (GET_BIT(I2Cx->SR1,I2C_REG_SR1_RXNE_FLAG) == 0 );


				/* Read data from DR */
				*pBuffPtr = (u8)I2Cx->DR;

				/* Increment Buffer pointer */
				pBuffPtr++;

				/* Update counter */
				XferSize--;
				XferCount--;

			}
		}


}


/*
 * function : send data from slave to master
 * parameter:	I2C_Type : I2C 1   or I2C 2
 * 			   data: data to be send
 * 			   len: length of the data
 * */
void I2C_Slavesend(u8 I2C_Type,u8* data,u8 len)
{

	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}

			/* Disable Pos */
		CLR_BIT(I2Cx->CR1, I2C_REG_CR1_POS);
			/* enable ACK */
		SET_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

		/* Wait until ADDR flag is set */
			while(GET_BIT(I2Cx->SR1,I2C_REG_SR1_ADDR_MATCHED_FLAG)==0);

			/* Clear ADDR flag */
						u16 val;

							val = I2Cx->SR1;
							val = I2Cx->SR2;

							// send data to DR register from data variable //

			if ( GET_BIT(I2Cx->SR2, I2C_REG_SR2_TRA_FLAG ) == I2C_TX_MODE)
				{
					u8  size = len;
					while(size>0)
					{
						I2Cx->DR = data[len-size];
						while( GET_BIT(I2Cx->SR1 ,I2C_REG_SR1_TXE_FLAG) == 0 ); //waiting for TxE
						size--;
					}
				}
				if ( GET_BIT(I2Cx->SR1,I2C_REG_SR1_AF_FAILURE_FLAG) == 1 ) //AF bit for tx
				{
					CLR_BIT(I2Cx->SR1,I2C_REG_SR1_AF_FAILURE_FLAG); //clear AF bit
				}


}


/*
 * function : recive data fromm master
 * parameter:	I2C_Type : I2C 1   or I2C 2
 * 			    buff: variable to store data from master
 * 			    len: length of the data
 * */
void I2C_Slaverecive(u8 I2C_Type,u8* buff, u8 len)
{

	if(I2C_Type == 1)
		{
			I2Cx = I2C_1;
		}else if(I2C_Type == 2)
		{
			I2Cx = I2C_2;
		}

				/* Disable Pos */
			CLR_BIT(I2Cx->CR1, I2C_REG_CR1_POS);
				/* enable ACK */
			SET_BIT(I2Cx->CR1, I2C_REG_CR1_ACK);

			/* Wait until ADDR flag is set */
				while(GET_BIT(I2Cx->SR1,I2C_REG_SR1_ADDR_MATCHED_FLAG)==0);

				/* Clear ADDR flag */
						u16 val;

						val = I2Cx->SR1;
						val = I2Cx->SR2;

						/// select the recieve data and assine it to buffer///

				if ( GET_BIT(I2Cx->SR2, I2C_REG_SR2_TRA_FLAG ) == I2C_RX_MODE)
					{
						u8  size = len;
						while(size>0)
						{
							while( GET_BIT(I2Cx->SR1, I2C_REG_SR1_RXNE_FLAG ) == 0 );  //waiting for RxNE
							buff[len-size] = I2Cx->DR;
							size--;
						}
					}

}

FlagStatus I2C_GetFlagStatus(I2C_reg* I2Cx,Status flag){
	volatile u32 dummyRead
}
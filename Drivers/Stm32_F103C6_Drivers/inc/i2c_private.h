/*
 * i2c_private.h
 *
 *  Created on: Nov 30, 2022
 *      Author: moham
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


typedef struct  {
		
		volatile u32 CR1;
		//containg clock of the aeb bus for sm mode >2MHZ in fm mode >4mhz
		volatile u32 CR2;
		//Containg the address
		volatile u32 OAR1;
		//Containg the second address dual address mode activated
		volatile u32 OAR2;
		volatile u32 DR;
		volatile u32 SR1;
		volatile u32 SR2;
		volatile u32 CCR;
		volatile u32 TRISE;
}I2C_reg;
typedef enum {RESET = 0 ,SET=1} FlagStatus;
typedef enum{
		I2C_FLAG_BUSY=0
}Status
// PORTA base address: 0x40010800
#define I2C_1				((volatile i2c_reg*) 0x40005400)
// PORTB base address: 0x40010C00
#define I2C_2				((volatile i2c_reg*) 0x40005800)

#endif /* I2C_PRIVATE_H_ */

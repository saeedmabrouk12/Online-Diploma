/*
 * i2c_interface.h
 *
 *  Created on: Nov 30, 2022
 *      Author: moham
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


/*******************  Bit definition for I2C_CR1 register  ********************/

#define I2C_REG_CR1_POS					11

#define I2C_REG_CR1_ACK					10
#define I2C_ACK_ENABLE      			1
#define I2C_ACK_DISABLE      			0

#define I2C_REG_CR1_STOP_GEN             9
#define I2C_REG_CR1_START_GEN            8

#define I2C_REG_CR1_NOSTRETCH            7
#define I2C_ENABLE_CLK_STRETCH  		 0
#define I2C_DISABLE_CLK_STRETCH 		 1

#define I2C_REG_CR1_ENABLE_I2C           0

/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_REG_CR2_BUF_INT_ENABLE       10
#define I2C_REG_CR2_EVT_INT_ENABLE       9
#define I2C_REG_CR2_ERR_INT_ENABLE       8

#define I2C_PERIPHERAL_CLK_FREQ_36MHZ    ((u32)36 )


/*******************  Bit definition for I2C_OAR1 register  ********************/
#define I2C_REG_OAR1_ADDRMODE       	 15
#define I2C_ADDRMODE_7BIT         		 0
#define I2C_ADDRMODE_10BI        		 1


/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_REG_SR1_TIMEOUT_FLAG         14
#define I2C_REG_SR1_OVR_FLAG             11
#define I2C_REG_SR1_AF_FAILURE_FLAG      10
#define I2C_REG_SR1_ARLO_FLAG            9
#define I2C_REG_SR1_BUS_ERROR_FLAG       8
#define I2C_REG_SR1_TXE_FLAG             7
#define I2C_REG_SR1_RXNE_FLAG            6
#define I2C_REG_SR1_STOP_DETECTION_FLAG  4 				/*  for slave */
#define I2C_REG_SR1_BTF_FLAG             2
#define I2C_REG_SR1_ADDR_FLAG            1
#define I2C_REG_SR1_ADDR_SENT_FLAG       1   			//For master
#define I2C_REG_SR1_ADDR_MATCHED_FLAG    1  			//For SLAVE
#define I2C_REG_SR1_SB_FLAG              0

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_REG_SR2_BUS_BUSY_FLAG        1
#define I2C_BUS_IS_BUSY                  1
#define I2C_BUS_IS_FREE                  0

#define I2C_REG_SR2_MSL_FLAG           	 0
#define I2C_MASTER_MODE        	         1
#define I2C_SLAVE_MODE                   0

#define I2C_REG_SR2_TRA_FLAG       		 2
#define I2C_RX_MODE                   	 0
#define I2C_TX_MODE                      1

/*******************  Bit definition for I2C_CCR register  ********************/
#define I2C_REG_CCR_ENABLE_FM            15
#define I2C_ENABLE_SM                    0
#define I2C_ENABLE_FM                    1

#define I2C_REG_CCR_DUTY                 14
#define I2C_FM_DUTY_16BY9                1
#define I2C_FM_DUTY_2                    0
/*******************  Bit definition for I2C_DR register  ********************/
#define I2C_ADDREES_READ				 1
#define I2C_ADDREES_WRITE				 0




/*
 * function : generate start bit for the frame (TX oR RX frame)
 * parameter: I2C_Type   I2C 1 or 2
 */
void I2C_generate_start_condition(u8 I2C_Type);




/*
 * function : generate start bit for the frame (TX oR RX frame)
 * parameter:  I2C_Type   I2C 1 or 2
 * */
void I2C_generate_stop_condition(u8 I2C_Type);




/*
 * function : check stop bit from the frame
 * parameter:  I2C_Type   I2C 1 or 2
 * */
void I2C_slave_Check_StopBit(u8 I2C_Type);




/*
 * function : select the clock and duty cycle of the I2C
 * parameter : clkspeed : speed of clock
 * 				duty_cycle : select the duty cicle
 *
 * */

static void I2C_clk_init ( u32 clkspeed, u32 duty_cycle);




/*
 * function : initialize the configuration of the I2C type
 * parameter: I2C_Type : I2C 1   or I2C 2
 * 			  I2C_clock : select the clock of the I2C
 * 			  OwnAddress1: set the address of the micro_controller (if master or slave )
 * */
void i2c_init(u8 I2C_Type,u32 I2C_CLOCK, u16 OwnAddress1);


/*
 * function : send data from master to slave
 * parameter:	I2C_Type : I2C 1   or I2C 2
 * 			  	address : select the address of the slave to send data to
 * 			  	data: data to be sent
 * 			  	len: length of the data
 * */
void i2c_Mastersend(u8 I2C_Type,u8 address,u8* data,u8 len);


/*
 * function : receive data from a selected slave
 * parameter:  I2C_Type : I2C 1   or I2C 2
 * 			   address : select the address of the slave to receive data from
 * 			   pdata: data to be receive
 * 			   len: length of the data
 * */
void i2c_Masterrecive(u8 I2C_Type, u16 address, u8 *pData, u8 len);


/*
 * function : send data from slave to master
 * parameter:	I2C_Type : I2C 1   or I2C 2
 * 			   data: data to be send
 * 			   len: length of the data
 * */
void i2c_Slavesend(u8 I2C_Type,u8* data,u8 len);


/*
 * function : recive data fromm master
 * parameter:	I2C_Type : I2C 1   or I2C 2
 * 			    buff: variable to store data from master
 * 			    len: length of the data
 * */
void i2c_Slaverecive(u8 I2C_Type,u8* buff, u8 len);


#endif /* I2C_INTERFACE_H_ */

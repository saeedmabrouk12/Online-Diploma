/*
 * DIO.h
 *
 * Created: 8/11/2023 3:12:10 PM
 *  Author: saeed
 */ 
#include <Platform_Types.h>

#ifndef DIO_H_
#define DIO_H_

	#define SFIOR	*(volatile uint8 *)0x50
	
	#define PORTA	*(volatile uint8 *)0x3B
	#define DDRA	*(volatile uint8 *)0x3A
	#define PINA	*(volatile uint8 *)0x39
	
	#define PORTB	*(volatile uint8 *)0x38
	#define DDRB	*(volatile uint8 *)0x37
	#define PINB	*(volatile uint8 *)0x36
	
	
	#define PORTC	*(volatile uint8 *)0x35
	#define DDRC	*(volatile uint8 *)0x34
	#define PINC	*(volatile uint8 *)0x33
	
	
	#define PORTD	*(volatile uint8 *)0x32
	#define DDRD	*(volatile uint8 *)0x31
	#define PIND	*(volatile uint8 *)0x30
	
	typedef enum {
		PORT_A,PORT_B,PORT_C,PORT_D
	}PORT;
	typedef enum {
		PIN_0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7
	}PIN;
	typedef enum {
		INPUT,OUTPUT
	}PINSTATE;
	typedef enum {
		LOW,HIGH
	}PINVOLT;
	
	
	
// Arguments is port name and pin name
void MCAL_GPIO_setPinMode(PORT port,PIN pin,PINSTATE ps);
void MCAL_GPIO_setPortMode(PORT port,PINSTATE ps);
void MCAL_GPIO_setPinValue(PORT port,PIN pin,PINVOLT pv);
PINVOLT MCAL_GPIO_readPinValue(PORT port,PIN pin);

#endif /* DIO_H_ */
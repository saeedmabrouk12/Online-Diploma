/*
 * DIO.c
 *
 * Created: 8/11/2023 3:11:54 PM
 *  Author: saeed
 */ 
#include <DIO.h>
#include <BIT_MATH.h>

void MCAL_GPIO_setPinMode(PORT port,PIN pin,PINSTATE ps){
	switch (port){
		case PORT_A:
			if (ps==INPUT)
			{
				CLR_BIT(DDRA,pin);
				//to enable pull up resistor
				SET_BIT(PORTA,pin);
			}
			else
			{
				SET_BIT(DDRA,pin);
			}
			break;
		case PORT_B:
		if (ps==INPUT)
		{
			CLR_BIT(DDRB,pin);
			SET_BIT(PORTB,pin);
		}
		else
		{
			SET_BIT(DDRB,pin);
		}
		break;
		case PORT_C:
		if (ps==INPUT)
		{
			CLR_BIT(DDRC,pin);
			SET_BIT(PORTC,pin);
		}
		else
		{
			SET_BIT(DDRC,pin);
		}
		break;
		case PORT_D:
		if (ps==INPUT)
		{
			CLR_BIT(DDRD,pin);
			SET_BIT(PORTD,pin);
		}
		else
		{
			SET_BIT(DDRD,pin);
		}
		break;
	}
}
void MCAL_GPIO_setPortMode(PORT port,PINSTATE ps){
	switch(port){
		case PORT_A:
			if(ps==INPUT){
				PORTA=0x00000000;
			}else{
				PORTA=0x11111111;
			}
			break;
		case PORT_B:
		if(ps==INPUT){
			PORTB=0x00000000;
			}else{
			PORTB=0x11111111;
		}
		break;
		case PORT_C:
		if(ps==INPUT){
			PORTC=0x00000000;
			}else{
			PORTC=0x11111111;
		}
		break;
		case PORT_D:
		if(ps==INPUT){
			PORTD=0x00000000;
			}else{
			PORTD=0x11111111;
		}
		break;
	}
	
}
void MCAL_GPIO_setPinValue(PORT port,PIN pin,PINVOLT pv){
		switch (port){
			case PORT_A:
			if (pv==LOW)
			{
				CLR_BIT(PORTA,pin);
			}
			else
			{
				SET_BIT(PORTA,pin);
			}
			break;
			case PORT_B:
			if (pv==LOW)
			{
				CLR_BIT(PORTB,pin);
			}
			else
			{
				SET_BIT(PORTB,pin);
			}
			break;
			case PORT_C:
			if (pv==LOW)
			{
				CLR_BIT(PORTC,pin);
			}
			else
			{
				SET_BIT(PORTC,pin);
			}
			break;
			case PORT_D:
			if (pv==LOW)
			{
				CLR_BIT(PORTD,pin);
			}
			else
			{
				SET_BIT(PORTD,pin);
			}
			break;
		}
}
PINVOLT MCAL_GPIO_readPinValue(PORT port,PIN pin){
	switch (port){
		case PORT_A:
			return GET_BIT(PINA,pin);
		case PORT_B:
			return GET_BIT(PINB,pin);
		case PORT_C:
			return GET_BIT(PINC,pin);
		case PORT_D:
			return GET_BIT(PIND,pin);
	}
}
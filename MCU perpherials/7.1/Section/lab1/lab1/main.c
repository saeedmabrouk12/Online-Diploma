/*
 * lab1.c
 *
 * Created: 9/16/2022 2:05:46 PM
 * Author : Haytham
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

#include <util/delay.h>
#define PORTDD *(volatile uint8_t *)(0x32)
#define DDRDD *(volatile uint8_t *)(0x31)

void delay (void){
	volatile int i,j;
	for(i = 0 ; i< 10;i++)
		for(j = 0 ;j < 20000;j++);
}
int main(void)
{
    /* Replace with your application code */
	DDRDD = (1<<4 |1<<5|1<<6|1<<7);
	
	PORTDD =0b00000000;
    while (1) 
    {
		
		PORTDD = 0b00100000;
		delay();
		PORTDD = 0b01000000;
		delay();
		PORTDD = 0b10000000;
		delay();
		PORTDD = 0b00010000;
		delay();
		
		
		
				
    }
}


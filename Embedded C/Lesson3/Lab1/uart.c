#include <stdio.h>
#include<uart.h>
#define UART0 *((volatile char* const)(( char*)0x101f1000))
void Uart_send_string(char arr[]){
	while(*arr!='\0'){
		UART0=*arr;
		arr++;
	}
}
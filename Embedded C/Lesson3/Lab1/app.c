#include<stdio.h>
#include<uart.h>

char arr[100]="learn-in-depth: Saeed Fares";

void main(void){
	Uart_send_string(arr);
}
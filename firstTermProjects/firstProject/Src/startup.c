
//startup.c
//Saeed
#include<stdint.h>
void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}

void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
//booking 1024 B located by .bss through un initrialized array of int 256 element(256*4B = 1024)
//static to prevent another file of edit 
static unsigned long stack_top[256];
int main(void);
//extern unsigned int _stack_top;


	void (* const g_p_fn[])()__attribute__((section(".vectors")))={
		(void (*)()) ((unsigned long)stack_top+sizeof(stack_top)),
		&Reset_Handler,
		&NMI_Handler,
		&H_fault_Handler,
	};


extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	//copuy data section from flash to ram
	unsigned int data_section= (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_data;
	for(int i = 0 ; i< data_section;i++){
		*(P_dst++)=*(P_src++);
	}
	//init bss and make it zeroooooooooooo
	unsigned int bss_section= (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst=(unsigned char*)&_S_bss;
	for(int i = 0 ; i < bss_section;i++){
		*(P_dst++)=(unsigned char)0;
	}
	main();
}


//startup.c
//Saeed
#include<stdint.h>
void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}

void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void MM_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void Bus_fault()__attribute__((weak,alias("Default_Handler")));
void Usange_fault_Handler()__attribute__((weak,alias("Default_Handler")));
int main(void);
extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usange_fault_Handler,




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

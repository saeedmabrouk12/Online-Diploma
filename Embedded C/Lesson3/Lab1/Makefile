#copyright : Saeed
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name=learn-in-depth
# : mean every member  

#we can call target from other target
saeed:learn-in-depth.bin
	@echo +++Build is done++++++++
	
%.o:%.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS)  $< -o $@



startup.o:startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@


$(project_name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@
$(project_name).bin:$(project_name).elf
	$(CC)objcopy.exe -O binary $(project_name).elf $(project_name).bin

clean_all:
	rm *.o *.bin *.elf

clean:
	rm *.elf *.bin

cleanO:
	rm *.o
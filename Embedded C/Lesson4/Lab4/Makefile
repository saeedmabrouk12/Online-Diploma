#copyright : Saeed
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name=learn-in-depth_cortex_m4
# : mean every member  

#we can call target from other target
tt:$(project_name).bin
	@echo +++Build is done++++++++
	
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS)  $< -o $@



%.o:%.s
	$(CC)as.exe $(CFLAGS) $< -o $@


$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.bin *.elf

clean:
	rm *.elf *.bin

cleanO:
	rm *.o
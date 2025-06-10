CC := /home/hao/tools/toolchains/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
LD := /home/hao/tools/toolchains/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-ld
OBJCOPY := /home/hao/tools/toolchains/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-objcopy
OBJDUMP := /home/hao/tools/toolchains/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-objdump


test.bin: start.o clock.o uart.o test.o
	$(LD) -Ttext 0xD0020010 -o test.elf $^
	$(OBJCOPY) -O binary test.elf test.bin
	$(OBJDUMP) -D test.elf > test.dis
%.o: %.c
	$(CC) -nostdlib -c $< -o $@
%.o: %.S
	$(CC) -nostdlib -c $^ -o $@

clean:
	rm *.o *.elf *.bin *.dis


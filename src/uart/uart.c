#include "../../s5pv210.h"
#include "uart.h"

void uart0_init(void){
    // Configure GPA0[0] as RXD0 and GPA0[1] as TXD0
    GPA0CON &= ~0xFF;
    GPA0CON |= 0x22;

    // Set line control: 8N1 (8 data bits, no parity, 1 stop bit)
    ULCON0 = (0x3 << 0);

    // Set control: PCLK source, polling mode
    UCON0 = (1 << 0) | (1 << 2);

    // Disable FIFOs
    UFCON0 = 0;

    // Set baud rate
    // PCLK_PSYS = 66MHz (from clock_init)
    // UBRDIV = (PCLK / (Baudrate * 16)) - 1
    // UBRDIV = (66,000,000 / (115200 * 16)) - 1 = 34.7
    UBRDIV0 = 35; // rounded
    UDIVSLOT0 = 0xDDDD; // Slot values can be fine-tuned
}


void putc(unsigned char c)
{
    // Wait until transmit buffer is empty
    while(!(UTRSTAT0 & (1 << 2)));
    UTXH0 = c;
}

unsigned char getc(void){
    // Wait until receive buffer has data
    while(!(UTRSTAT0 & (1 << 0)));
    return (URXH0);
}

void puts(char *str){
    char *p = str;
    while(*p) {
        putc(*p++);
    }
}
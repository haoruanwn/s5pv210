#ifndef UART_H
#define UART_H

void uart0_init(void);
void putc(unsigned char c);
unsigned char getc(void);
void puts(char *str);

#endif //UART_H
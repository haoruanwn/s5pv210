#include "s5pv210.h"
#include "src/uart/uart.h"
#include "src/led/led.h"
#include "src/key/key.h"
#include "src/timer/timer.h"
#include "src/clock/clock.h"


void receive() {
    unsigned char c;
    c = getc();

    if (c == 'M') {
        puts("\r\nMusic command received. Playing in 3 seconds...\r\n");
        delay(0x200000); // Adjust delay value as needed
        puts("\r\nPlaying music...\r\n");
        music();
        puts("\r\nMusic finished.\r\n");
    }
}


int main(void) {
    clock_init();
    uart0_init();
    led_init();
    sw4_init();
    int_init();

    puts("\r\nSystem Initialized. Press 'M' to play music or press SW4 for marquee.\r\n");

    while (1) {
        receive();
    }
    return 0;
}
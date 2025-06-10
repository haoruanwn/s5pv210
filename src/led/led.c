#include "s5pv210.h"
#include "led.h"
#include "timer.h"

void led_init(void) {
    // Configure GPJ2[0-3] as output pins
    GPJ2CON &= ~0xFFFF;
    GPJ2CON |= 0x1111;
    // Turn all LEDs off initially (active low)
    GPJ2DAT |= 0xF;
}

void led(void) {
    int i;
    unsigned long led_delay = 0x100000;

    // Forward marquee
    for (i = 0; i < 4; i++) {
        GPJ2DAT = ~(1 << i);
        delay(led_delay);
    }
    GPJ2DAT = 0xF; // Off
    delay(led_delay);

    // Backward marquee
    for (i = 0; i < 4; i++) {
        GPJ2DAT = ~(1 << (3 - i));
        delay(led_delay);
    }

    // Blink all
    GPJ2DAT = 0x0; // On
    delay(led_delay);
    GPJ2DAT = 0xF; // Off
}
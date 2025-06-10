#include "../../s5pv210.h"
#include "timer.h"

void delay(volatile unsigned long dly) {
    while (dly--);
}

void pwm_init(int tone_val) {
    // Configure GPD0_2 as TOUT_2 for PWM output
    GPD0CON &= ~(0xF << 8);
    GPD0CON |= (0x2 << 8);

    // Timer clock = PCLK / (prescaler + 1) / (divider)
    // PCLK_PSYS = 66MHz (from clock_init)
    // Prescaler = 65 + 1 = 66
    // Divider = 16 (0x4)
    // Timer clock = 66MHz / 66 / 16 = 62.5 KHz

    TCFG0 &= ~(0xFF << 8);
    TCFG0 |= (65 << 8); // Prescaler value for timer 2

    TCFG1 &= ~(0x0F << 8);
    TCFG1 |= (0x04 << 8); // Divider value for timer 2 (1/16)

    // TCNTB2 values for different notes
    // Frequency = Timer Clock / TCNTB2
    int tcntb_values[] = {0, 241, 214, 191, 180, 161, 143, 127, 124, 110, 98, 93, 82, 74, 65};

    if (tone_val >= 0 && tone_val <= 14) {
        TCNTB2 = tcntb_values[tone_val];
        TCMPB2 = TCNTB2 / 2; // 50% duty cycle
    } else {
        TCNTB2 = 0;
        TCMPB2 = 0;
    }

    // Start timer 2: manual update, inverter on, auto-reload on
    TCON |= (1 << 13);  // Manual update TCNTB2 & TCMPB2
    TCON &= ~(1 << 13); // Clear manual update
    TCON |= (1 << 15);  // Inverter on for TOUT2
    TCON |= (1 << 12);  // Start timer 2
}

void tone(unsigned char i) {
    pwm_init(i);
    delay(0x1FFFFF);
    GPD0CON &= ~(0xF << 8); // Stop PWM output
}

void music() {
    int notes[] = {5, 3, 8, 0, 6, 8, 12, 0, 5, 1, 3, 2, 2, 0, 5, 3, 8, 7, 6, 8, 5, 0, 12, 9, 11, 7, 8, 0, 6, 8, 8, 0, 7, 6, 8, 0, 6, 8, 6, 3, 2, 0, 5, 3, 8, 7, 6, 8, 5, 0, 12, 9, 11, 7, 8, 0};
    for (int i = 0; i < sizeof(notes)/sizeof(notes[0]); i++) {
        tone(notes[i]);
    }
}
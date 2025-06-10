#include "../../s5pv210.h"
#include "key.h"
#include "../timer/timer.h"
#include "../led/led.h"
#include "../uart/uart.h"

static void clear_int_pend(void) {
    EXT_INT_0_PEND |= (1 << 2); // Clear EXT_INT[2] pending bit
}

static void clear_vectaddr(void) {
    VIC0ADDRESS = 0x0; // Clear the VIC vector address register
}

void show_sw_triggered() {
    puts("\r\nSW4 pressed. Running marquee LEDs.\r\n");
}

void sw4_init(void) {
    // Configure GPH0_2 as an external interrupt pin (EINT[2])
    GPH0CON &= ~(0xF << 8);
    GPH0CON |= (0xF << 8);

    // Configure EINT[2] for falling edge trigger
    EXT_INT_0_CON &= ~(0xF << 8);
    EXT_INT_0_CON |= (0x2 << 8);

    // Unmask EINT[2]
    EXT_INT_0_MASK &= ~(1 << 2);
}

void int_init(void) {
    // Configure EINT[2] (interrupt source 2) as IRQ, not FIQ
    VIC0INTSELECT &= ~(1 << 2);

    // Set the ISR for interrupt source 2
    VIC0VECTADDR2 = (unsigned int)key_isr;

    // Enable the interrupt in the VIC
    VIC0INTENABLE |= (1 << 2);

    // Clear VIC address register initially
    clear_vectaddr();
}


void key_handle(void) {
    delay(0x1000); // Debounce delay

    // Check if the interrupt was from EINT[2]
    if (VIC0IRQSTATUS & (1 << 2)) {
        led();
        show_sw_triggered();
    }

    clear_vectaddr();
    clear_int_pend();
}
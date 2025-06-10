#ifndef S5PV210_H
#define S5PV210_H

// Clock & Power
#define APLLCON0 *((volatile unsigned int *) 0xE0100100)
#define MPLLCON *((volatile unsigned int *) 0xE0100108)
#define EPLLCON0 *((volatile unsigned int *) 0xE0100110)
#define VPLLCON *((volatile unsigned int *) 0xE0100120)
#define CLK_SRC0 *((volatile unsigned int *) 0xE0100200)
#define CLK_DIV0 *((volatile unsigned int *) 0xE0100300)
#define CLK_DIV1 *((volatile unsigned int *) 0xE0100304)
#define CLK_DIV2 *((volatile unsigned int *) 0xE0100308)
#define CLK_DIV3 *((volatile unsigned int *) 0xE010030C)

// GPIO
#define GPH0CON *((volatile unsigned int *) 0xE0200C00)
#define GPH0DAT *((volatile unsigned int *) 0xE0200C04)
#define GPJ2CON *((volatile unsigned int *) 0xE0200280)
#define GPJ2DAT *((volatile unsigned int *) 0xE0200284)
#define GPD0CON (*(volatile unsigned long *) 0xE02000A0)
#define GPD0DAT (*(volatile unsigned long *) 0xE02000A4)
#define GPA0CON *((volatile unsigned int *) 0xE0200000)


// External Interrupts
#define EXT_INT_0_CON *((volatile unsigned int *) 0xE0200E00)
#define EXT_INT_0_MASK *((volatile unsigned int *) 0xE0200F00)
#define EXT_INT_0_PEND *((volatile unsigned int *) 0xE0200F40)

// VIC (Vectored Interrupt Controller)
#define VIC0IRQSTATUS *((volatile unsigned int *) 0xF2000000)
#define VIC0INTSELECT *((volatile unsigned int *) 0xF200000C)
#define VIC0INTENABLE *((volatile unsigned int *) 0xF2000010)
#define VIC0VECTADDR2 *((volatile unsigned int *) 0xF2000108)
#define VIC0ADDRESS *((volatile unsigned int *) 0xF2000F00)

// PWM Timer
#define TCFG0 (*(volatile unsigned long *) 0xE2500000)
#define TCFG1 (*(volatile unsigned long *) 0xE2500004)
#define TCON (*(volatile unsigned long *) 0xE2500008)
#define TCNTB2 (*(volatile unsigned long *) 0xE2500024)
#define TCMPB2 (*(volatile unsigned long *) 0xE2500028)


// UART
#define ULCON0 *((volatile unsigned int *) 0xE2900000)
#define UCON0 *((volatile unsigned int *) 0xE2900004)
#define UFCON0 *((volatile unsigned int *) 0xE2900008)
#define UTRSTAT0 *((volatile unsigned int *) 0xE2900010)
#define UTXH0 *((volatile unsigned int *) 0xE2900020)
#define URXH0 *((volatile unsigned int *) 0xE2900024)
#define UBRDIV0 *((volatile unsigned int *) 0xE2900028)
#define UDIVSLOT0 *((volatile unsigned int *) 0xE290002C)


#endif // S5PV210_H

#ifndef S5PV210_H
#define S5PV210_H

/***************************** GPIO *****************************/
#define GPA0CON         (*(volatile unsigned int *)0xE0200000)

#define GPC1CON         (*(volatile unsigned int *)0xE0200060)
#define GPC1DAT         (*(volatile unsigned int *)0xE0200064)
#define GPC1PUD         (*(volatile unsigned int *)0xE0200068)

#define GPD0CON         (*(volatile unsigned int *)0xE02000A0)
#define GPD0DAT         (*(volatile unsigned int *)0xE02000A4)

#define GPH0CON         (*(volatile unsigned int *)0xE0200C00)
#define GPH0DAT         (*(volatile unsigned int *)0xE0200C04)
#define GPH0PUD         (*(volatile unsigned int *)0xE0200C08)

#define GPH1CON         (*(volatile unsigned int *)0xE0200C20)

#define GPJ2CON         (*(volatile unsigned int *)0xE0200280)
#define GPJ2DAT         (*(volatile unsigned int *)0xE0200284)
#define GPJ2PUD         (*(volatile unsigned int *)0xE0200288)


/***************************** UART *****************************/
#define ULCON0          (*(volatile unsigned int *)0xE2900000)
#define UCON0           (*(volatile unsigned int *)0xE2900004)
#define UFCON0          (*(volatile unsigned int *)0xE2900008)
#define UTRSTAT0        (*(volatile unsigned int *)0xE2900010)
#define UTXH0           (*(volatile unsigned int *)0xE2900020)
#define URXH0           (*(volatile unsigned int *)0xE2900024)
#define UBRDIV0         (*(volatile unsigned int *)0xE2900028)
#define UDIVSLOT0       (*(volatile unsigned int *)0xE290002C)


/***************************** 中断 *****************************/
#define EXT_INT_0_CON   (*(volatile unsigned int *)0xE0200E00)
#define EXT_INT_0_MASK  (*(volatile unsigned int *)0xE0200F00)
#define EXT_INT_0_PEND  (*(volatile unsigned int *)0xE0200F40)

#define EXT_INT_1_CON   (*(volatile unsigned int *)0xE0200E04)
#define EXT_INT_1_MASK  (*(volatile unsigned int *)0xE0200F04)
#define EXT_INT_1_PEND  (*(volatile unsigned int *)0xE0200F44)

#define VIC0IRQSTATUS   (*(volatile unsigned int *)0xF2000000)
#define VIC0INTSELECT   (*(volatile unsigned int *)0xF200000C)
#define VIC0INTENABLE   (*(volatile unsigned int *)0xF2000010)
#define VIC0INTENCLEAR  (*(volatile unsigned int *)0xF2000014)
#define VIC0VECTADDR0   (*(volatile unsigned int *)0xF2000100)
#define VIC0VECTADDR2   (*(volatile unsigned int *)0xF2000108)
#define VIC0VECTADDR3   (*(volatile unsigned int *)0xF200010C)
#define VIC0VECTADDR4   (*(volatile unsigned int *)0xF2000110)
#define VIC0VECTADDR8   (*(volatile unsigned int *)0xF2000120)
#define VIC0ADDRESS     (*(volatile unsigned int *)0xF2000F00)


/***************************** PLL/Clock *****************************/
#define APLLCON0        (*(volatile unsigned int *)0xE0100100)
#define MPLLCON         (*(volatile unsigned int *)0xE0100108)
#define EPLLCON0        (*(volatile unsigned int *)0xE0100110)
#define VPLLCON         (*(volatile unsigned int *)0xE0100120)

#define CLK_SRC0        (*(volatile unsigned int *)0xE0100200)
#define CLK_DIV0        (*(volatile unsigned int *)0xE0100300)
#define CLK_DIV1        (*(volatile unsigned int *)0xE0100304)
#define CLK_DIV2        (*(volatile unsigned int *)0xE0100308)
#define CLK_DIV3        (*(volatile unsigned int *)0xE010030C)


/***************************** 定时器 *****************************/
#define TCFG0           (*(volatile unsigned int *)0xE2500000)
#define TCFG1           (*(volatile unsigned int *)0xE2500004)
#define TCON            (*(volatile unsigned int *)0xE2500008)
#define TCNTB2          (*(volatile unsigned int *)0xE2500024)
#define TCMPB2          (*(volatile unsigned int *)0xE2500028)


/***************************** 中断触发方式宏 *****************************/
#define EXT_INT_MODE_LOW_LEVEL       (0x0)
#define EXT_INT_MODE_HIGH_LEVEL      (0x1)
#define EXT_INT_MODE_FALLING_EDGE    (0x2)
#define EXT_INT_MODE_RISING_EDGE     (0x3)
#define EXT_INT_MODE_BOTH_EDGE       (0x4)

#endif // S5PV210_H

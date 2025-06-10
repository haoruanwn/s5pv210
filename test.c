extern void uart0_init(void);

#define GPH0CON *((volatile unsigned int *) 0xE0200C00)
#define GPH0DAT *((volatile unsigned int *) 0xE0200C04) // sw

#define GPJ2CON *((volatile unsigned int *) 0xE0200280)
#define GPJ2DAT *((volatile unsigned int *) 0xE0200284) // led

#define EXT_INT_0_CON *((volatile unsigned int *) 0xE0200E00)
#define EXT_INT_0_MASK *((volatile unsigned int *) 0xE0200F00)
#define EXT_INT_0_PEND *((volatile unsigned int *) 0xE0200F40) // exit

#define VIC0IRQSTATUS *((volatile unsigned int *) 0xF2000000)
#define VIC0INTSELECT *((volatile unsigned int *) 0xF200000C)
#define VIC0INTENABLE *((volatile unsigned int *) 0xF2000010)
#define VIC0VECTADDR2 *((volatile unsigned int *) 0xF2000108)
#define VIC0ADDRESS *((volatile unsigned int *) 0xF2000F00) // vic0

#define TCFG0 (*(volatile unsigned long *) 0xE2500000)
#define TCFG1 (*(volatile unsigned long *) 0xE2500004)
#define TCNTB2 (*(volatile unsigned long *) 0xE2500024)
#define TCMPB2 (*(volatile unsigned long *) 0xE2500028)
#define TCON (*(volatile unsigned long *) 0xE2500008) // pwm

#define GPD0CON (*(volatile unsigned long *) 0xE02000A0)
#define GPD0DAT (*(volatile unsigned long *) 0xE02000A4) // beep

extern key_isr();


void delay(volatile unsigned long dly) {
    volatile unsigned int t = 0xffff;
    while (dly--)
        for (; t > 0; t--)
            ;
}

void delays(int n) {
    int i;
    for (i = 0; i < n; i++)
        ;
}


sw4_init() {

    GPH0CON &= ~(0xf << 2 * 4);
    GPH0CON |= (0xf << 2 * 4);

    EXT_INT_0_CON &= ~(0xF << 2 * 4);
    EXT_INT_0_CON |= (0x2 << 2 * 4);

    EXT_INT_0_MASK &= ~0x4;
}


void clear_int_pend() {
    EXT_INT_0_PEND |= 0x4; // EXT_INT[2]
}


void int_init(void) {

    VIC0INTSELECT &= ~0x4;

    VIC0ADDRESS = 0x0;

    VIC0VECTADDR2 = (int) key_isr;

    VIC0INTENABLE |= 0x4;
}


void clear_vectaddr(void) { VIC0ADDRESS = 0x0; }

void key_handle() {
    delay(0x1000);
    volatile unsigned char key_val = VIC0IRQSTATUS & 0x4; //


    if (key_val == 0x04) {

        GPD0CON = 0;

        led();
        show_sw();
    }

    clear_vectaddr(); //?????-??-???é???ˉ??-????
    clear_int_pend(); //???pending???,?????-??-???èμ·?ˉ??-????
}


void pwm_init(int tone) {
    GPD0CON &= ~(0xF << 8);
    GPD0CON |= (0x2 << 8);
    TCFG0 &= ~(0xff << 8);
    TCFG0 |= (65 << 8);

    TCFG1 &= ~(0x0f << 8);
    TCFG1 |= (0x04 << 8);
    if (tone == 8) {
        TCNTB2 = 124; // 62500,63162
        TCMPB2 = 12; // TCNTB2
    }
    if (tone == 9) {
        TCNTB2 = 110; // 62500,63162
        TCMPB2 = 11; // TCNTB2
    }
    if (tone == 10) {
        TCNTB2 = 98; // 62500,63162
        TCMPB2 = 10; // TCNTB2
    }

    if (tone == 11) {
        TCNTB2 = 93; // 62500,63162
        TCMPB2 = 9; // TCNTB2
    }
    if (tone == 12) {
        TCNTB2 = 82; // 62500,63162
        TCMPB2 = 8; // TCNTB2
    }
    if (tone == 13) {
        TCNTB2 = 74; // 62500,63162
        TCMPB2 = 7; // TCNTB2
    }
    if (tone == 14) {
        TCNTB2 = 65; // 62500,63162
        TCMPB2 = 6; // TCNTB2
    }
    if (tone == 0) {
        TCNTB2 = 0; // 62500,63162
        TCMPB2 = 0; // TCNTB2
    }


    if (tone == 1) {
        TCNTB2 = 241; // 62500,63162
        TCMPB2 = 24; // TCNTB2
    }


    if (tone == 2) {
        TCNTB2 = 214; // 62500,63162
        TCMPB2 = 21; // TCNTB2
    }


    if (tone == 3) {
        TCNTB2 = 191; // 62500,63162
        TCMPB2 = 19; // TCNTB2
    }

    if (tone == 4) {
        TCNTB2 = 180; // 62500,63162
        TCMPB2 = 18; // TCNTB2
    }

    if (tone == 5) {
        TCNTB2 = 161; // 62500,63162
        TCMPB2 = 16; // TCNTB2
    }

    if (tone == 6) {
        TCNTB2 = 143; // 62500,63162
        TCMPB2 = 14; // TCNTB2
    }

    if (tone == 7) {
        TCNTB2 = 127; // 62500,63162
        TCMPB2 = 13; // TCNTB2
    }
    if (tone == 0) {
        TCNTB2 = 0; // 62500,63162
        TCMPB2 = 0; // TCNTB2
    }

    TCON |= (1 << 13);
    TCON &= ~(1 << 13); //??????????????°
    TCON |= (1 << 15);
    TCON |= (1 << 12);
}

void tone(unsigned char i) {
    switch (i) {

        case 1:
            pwm_init(1);
            break;
        case 2:
            pwm_init(2);
            break;
        case 3:
            pwm_init(3);
            break;
        case 4:
            pwm_init(4);
            break;
        case 5:
            pwm_init(5);
            break;
        case 6:
            pwm_init(6);
            break;
        case 7:
            pwm_init(7);
            break;
        case 8:
            pwm_init(8);
            break;
        case 9:
            pwm_init(9);
            break;
        case 10:
            pwm_init(10);
            break;
        case 11:
            pwm_init(11);
            break;
        case 12:
            pwm_init(12);
            break;
        case 13:
            pwm_init(13);
            break;
        case 14:
            pwm_init(14);
            break;
    }
    delay(0xffff);
    delay(0xffff); // delay1s();
    GPD0CON &= ~(0xf << 8);
}
void music() {
    tone(5);
    tone(3);
    tone(8);
    tone(0);
    tone(6);
    tone(8);
    tone(12);
    tone(0);
    tone(5);
    tone(1);
    tone(3);
    tone(2);
    tone(2);
    tone(0);
    tone(5);
    tone(3);
    tone(8);
    tone(7);
    tone(6);
    tone(8);
    tone(5);
    tone(0);
    tone(12);
    tone(9);
    tone(11);
    tone(7);
    tone(8);
    tone(0);
    tone(6);
    tone(8);
    tone(8);
    tone(0);
    tone(7);
    tone(6);
    tone(8);
    tone(0);
    tone(6);
    tone(8);
    tone(6);
    tone(3);
    tone(2);
    tone(0);
    tone(5);
    tone(3);
    tone(8);
    tone(7);
    tone(6);
    tone(8);
    tone(5);
    tone(0);
    tone(12);
    tone(9);
    tone(11);
    tone(7);
    tone(8);
    tone(0);
}


void show_sw() { puts("\r\nMarquee\r\n"); }


void show_uart() { puts("\r\nWaiting for music\r\n"); }

void receive() {
    unsigned char c;
    c = getc();

    if (c == 'M') {
        puts("\r\nWaiting for music\r\n");
        delay(3000000);
        puts("\r\nPlaying music\r\n");
        music();
    }
}

void led() {

    int i;

    for (i = 0; i < 4; i++) {
        GPJ2DAT = ~(1 << i);
        delay(0x100000);
        GPJ2DAT = 0xF;
        delay(0x100000);
    }
    GPJ2DAT = 0xF;
    delay(0x200000);
    for (i = 0; i < 4; i++) {
        GPJ2DAT = ~(1 << (3 - i));
        delay(0x100000);
        GPJ2DAT = 0xF;
        delay(0x100000);
    }
    GPJ2DAT = 0x0;
    delay(0x200000);
    GPJ2DAT = 0xF;
}

led_init() {
    GPJ2CON &= 0xffff;
    GPJ2CON |= 0x1111;
    GPJ2DAT |= 0xf;
}


//////////////////////////????????°//////////////////////////
int main(void) {
    uart0_init();
    led_init();
    sw4_init();
    int_init();
    while (1) {
        receive();
    }
}

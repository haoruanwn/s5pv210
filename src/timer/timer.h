#ifndef TIMER_H
#define TIMER_H

void delay(volatile unsigned long dly);
void pwm_init(int tone_val);
void tone(unsigned char i);
void music(void);

#endif //TIMER_H
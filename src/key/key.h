#ifndef KEY_H
#define KEY_H

void sw4_init(void);
void int_init(void);
void key_handle(void);
extern void key_isr(void); // External assembly function

#endif //KEY_H
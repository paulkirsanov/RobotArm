#ifndef __delay_tim4_h
#define __delay_tim4_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
/* --------------------------------------------------------------------------- */
void delay_ms(uint16_t value);
void delay_us(uint16_t value);
void delay_tim4_init(void);

#endif

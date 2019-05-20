#ifndef __led_h
#define __led_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
/* --------------------------------------------------------------------------- */
#define led_off					GPIOC->BSRR |= GPIO_BSRR_BS13
#define led_on					GPIOC->BSRR |= GPIO_BSRR_BR13
/* --------------------------------------------------------------------------- */

void led_init(void);
void led_blink(void);

#endif

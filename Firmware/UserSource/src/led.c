#include "led.h"
#include "delay_tim4.h"

void led_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH = 0x00200000;
}

void led_blink(void)
{
	GPIOC->BSRR |= GPIO_BSRR_BS13;
	delay_ms(5000);
	GPIOC->BRR |= GPIO_BRR_BR13;
	delay_ms(5000);
	GPIOC->BSRR |= GPIO_BSRR_BS13;
	delay_ms(5000);
}

#include "button.h"

void button_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6);
	GPIOB->CRL |= GPIO_CRL_CNF6_1;
	GPIOB->ODR |= GPIO_ODR_ODR6;
}

#include "timer.h"

void timer2_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	TIM2->PSC = 35999;
	TIM2->ARR = 99;
	TIM2->CNT = 0;
	TIM2->EGR = TIM_EGR_UG;
	
	TIM2->DIER |= TIM_DIER_UIE;
	
	TIM2->CR1 = TIM_CR1_CEN;
	NVIC_EnableIRQ(TIM2_IRQn);
}

void timer3_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	TIM3->PSC = 35999;
	TIM3->ARR = 499;
	TIM3->CNT = 0;
	TIM3->EGR = TIM_EGR_UG;
	
	TIM3->DIER |= TIM_DIER_UIE;
	
	TIM3->CR1 = TIM_CR1_CEN;
	NVIC_EnableIRQ(TIM3_IRQn);
}

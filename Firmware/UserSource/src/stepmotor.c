#include "stepmotor.h"

void stepmotor_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	
	GPIOB->CRH &= ~(GPIO_CRH_CNF12 | GPIO_CRH_CNF13 | GPIO_CRH_CNF14 | GPIO_CRH_CNF15);
	GPIOB->CRH |= (GPIO_CRH_MODE12_0 | GPIO_CRH_MODE13_0 | GPIO_CRH_MODE14_0 | GPIO_CRH_MODE15_0);
	
	GPIOA->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_CNF11);
	GPIOA->CRH |= (GPIO_CRH_MODE8_0 | GPIO_CRH_MODE11_0);
}

void set_direction(Direction dir)
{
	if(dir == CW)
	{
		GPIOB->BSRR |= GPIO_BSRR_BS12;
	}
	else if(dir == CCW)
	{
		GPIOB->BSRR |= GPIO_BSRR_BR12;
	}
}

void set_resolution(uint8_t resolution)
{
	switch(resolution)
	{
		case FULL_STEP:
			GPIOB->BSRR |= GPIO_BSRR_BR13;
			GPIOB->BSRR |= GPIO_BSRR_BR14;
			GPIOB->BSRR |= GPIO_BSRR_BR15;
			break;
		case HALF_STEP:
			GPIOB->BSRR |= GPIO_BSRR_BS13;
			GPIOB->BSRR |= GPIO_BSRR_BR14;
			GPIOB->BSRR |= GPIO_BSRR_BR15;
			break;
		case QUARTER_STEP:
			GPIOB->BSRR |= GPIO_BSRR_BR13;
			GPIOB->BSRR |= GPIO_BSRR_BS14;
			GPIOB->BSRR |= GPIO_BSRR_BR15;
			break;
		case EIGHTH_STEP:
			GPIOB->BSRR |= GPIO_BSRR_BS13;
			GPIOB->BSRR |= GPIO_BSRR_BS14;
			GPIOB->BSRR |= GPIO_BSRR_BR15;
			break;
		case SIXTEENTH_STEP:
			GPIOB->BSRR |= GPIO_BSRR_BS13;
			GPIOB->BSRR |= GPIO_BSRR_BS14;
			GPIOB->BSRR |= GPIO_BSRR_BS15;
			break;
		default:
			
			break;
	}
}

void disable(void)
{
	GPIOA->BSRR = GPIO_BSRR_BS11;
}

void enable(void)
{
	GPIOA->BSRR = GPIO_BSRR_BR11;
}

void step(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS8;
	delay_ms(1);
	GPIOA->BSRR |= GPIO_BSRR_BR8;
}

void set_step(uint32_t number, Direction direction, uint16_t speed)
{
	uint32_t i = 0;
	enable();
	set_direction(direction);
	for(i = 0; i < number; i++)
	{
		step();
		delay_ms(speed);
	}
	//disable();
}

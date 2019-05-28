#include "main.h"

char buffer_rx[RX_BUFFER_SIZE] = "\0";
volatile uint8_t rx_index = 0;
char str[100] = "\0";

char text[100] = {0};

uint8_t Tx_Buffer[] = "hello stm32\r\n";
uint8_t Rx_Buffer[5];

uint8_t x = 0;

Direction dir_stepper = CW;
uint16_t step_number_stepper = 0;
uint16_t speed_stepper = 0;
uint32_t current_position = 0;

void RCC_Init(void);

void USART2_IRQHandler(void)
{
	if(USART2->SR & USART_SR_RXNE)
	{
		USART2->SR &= ~USART_SR_RXNE;
		buffer_rx[rx_index++] = USART2->DR;
		
		if(rx_index == RX_BUFFER_SIZE)
		{
			rx_index = 0;
		}
	}
	
	if(USART2->SR & USART_SR_IDLE){}
	
	if(USART2->SR & USART_SR_TXE)
	{
		USART2->SR &= ~USART_SR_TXE;
	}
	
	if(USART2->SR & USART_SR_TC)
	{
		USART2->SR &= ~USART_SR_TC;
	}
}

void TIM2_IRQHandler(void)
{
	if(TIM2->SR & TIM_SR_UIF)
	{
		TIM2->SR &= ~TIM_SR_UIF;
		
		if((int)buffer_rx[0] == 0xF8)
		{
			if(buffer_rx[1] == 0x52)
			{
				dir_stepper = CW;
			}
			else if(buffer_rx[1] == 0x4C)
			{
				dir_stepper = CCW;
			}
			
			if(buffer_rx[2] == 0x46)
			{
				set_resolution(FULL_STEP);
			}
			else if(buffer_rx[2] == 0x48)
			{
				set_resolution(HALF_STEP);
			}
			else if(buffer_rx[2] == 0x51)
			{
				set_resolution(QUARTER_STEP);
			}
			else if(buffer_rx[2] == 0x45)
			{
				set_resolution(EIGHTH_STEP);
			}
			else if(buffer_rx[2] == 0x53)
			{
				set_resolution(SIXTEENTH_STEP);
			}
			
			step_number_stepper = buffer_rx[3] << 8 | buffer_rx[4];
			
			speed_stepper = buffer_rx[5] << 8 | buffer_rx[6];
			
			if((int)buffer_rx[7] == 0xE0)
			{
				set_step(step_number_stepper, dir_stepper, speed_stepper, &current_position);
				
				sprintf(str, "%d", current_position);
				lcd_setpos(0, 1);
				lcd_string(str);
			}
			
			for(x = 0; x < 8; x++)
			{
				buffer_rx[x] = 0;
			}
			rx_index = 0;
		}
		else
		{
			for(x = 0; x < 8; x++)
			{
				buffer_rx[x] = 0;
			}
			rx_index = 0;
		}
	}
}

void TIM3_IRQHandler(void)
{
	if(TIM3->SR & TIM_SR_UIF)
	{
		TIM3->SR &= ~TIM_SR_UIF;
		
		if(GPIOC->IDR & GPIO_IDR_IDR13)
			GPIOC->BSRR |= GPIO_BSRR_BR13;
		else
			GPIOC->BSRR |= GPIO_BSRR_BS13;
	}
}

int main(void)
{
	RCC_Init();
	delay_tim4_init();
	led_init();
	
	i2c2_init();
	lcd_init();
	lcd_clear();
	lcd_setpos(0, 0);
	lcd_string("stm32");
	button_init();
	usart2_init();
	timer2_init();
	timer3_init();

	stepmotor_init();
	set_start_position(&current_position);
	
	while(1)
	{
		
	}
}

void RCC_Init(void)
{
	RCC->CR |= ((uint32_t)RCC_CR_HSEON);												//Enable HSE
	while(!(RCC->CR & RCC_CR_HSERDY));													//Ready start HSE
	
	FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;					//Clock flash memory
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;														//AHB = SYSCLK/1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;														//APB1 = HCLK/4
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV4;														//APB2 = HCLK/4
	
	RCC->CFGR &= ~RCC_CFGR_PLLMULL;															//clear PLLMULL bits
	RCC->CFGR &= ~RCC_CFGR_PLLSRC;															//clear PLLSRC bits
	RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;														//clear PLLXPRE bits
	
	RCC->CFGR |= RCC_CFGR_PLLSRC;																//source HSE
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE;													//sorce HSE/1 = 8MHz
	RCC->CFGR |= RCC_CFGR_PLLMULL9;															//PLL x9: clock = 8MHz * 9 = 72 MHz
	
	RCC->CR |= RCC_CR_PLLON;																		//enable PLL
	while(!(RCC->CR & RCC_CR_PLLRDY));													//wait till PLL is ready
	
	RCC->CFGR &= ~RCC_CFGR_SW;																	//clear SW bits
	RCC->CFGR |= RCC_CFGR_SW_PLL;																//select surce SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1){}				//wait till PLL is used
}

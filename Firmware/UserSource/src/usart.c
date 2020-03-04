#include "usart.h"
#include "string.h"

void usart_send_data(USART_TypeDef *USART, char data)
{
	while(!(USART->SR & USART_SR_TXE));
	USART->DR = data;
}

void usart_send_string(USART_TypeDef *USART, char* str)
{
	uint8_t i = 0;
	while(str[i])
		usart_send_data(USART, str[i++]);
}

void usartSendArrar(USART_TypeDef *USART, uint8_t *Arrar)
{
	uint16_t length, i;
	length = strlen((char *)Arrar);
		
	for(i = 0; i < length; i++)
	{
		USART->SR &= ~USART_SR_TC;
		usart_send_data(USART, *Arrar);
		while(!(USART->SR & USART_SR_TC));
		Arrar++;
	}
}

void usart1_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	GPIOA->CRH &= ~GPIO_CRH_CNF9;
	GPIOA->CRH |= GPIO_CRH_CNF9_1;
	GPIOA->CRH |= GPIO_CRH_MODE9_0;
	
	GPIOA->CRH &= ~GPIO_CRH_CNF10;
	GPIOA->CRH |= GPIO_CRH_CNF10_0;
	GPIOA->CRH &= ~GPIO_CRH_MODE10_0;
	
	USART1->BRR = 0x009C; //baudrate 115200
	
	USART1->CR1 |= USART_CR1_UE;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_RXNEIE;
	
	USART1->CR1 &= ~USART_CR1_M;
	USART1->CR2 &= ~USART_CR2_STOP;
	
	NVIC_EnableIRQ(USART1_IRQn);
}

void usart2_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	GPIOA->CRL &= ~GPIO_CRL_CNF2;
	GPIOA->CRL |= GPIO_CRL_CNF2_1;
	GPIOA->CRL |= GPIO_CRL_MODE2_0;
	
	GPIOA->CRL &= ~GPIO_CRL_CNF3;
	GPIOA->CRL |= GPIO_CRL_CNF3_0;
	GPIOA->CRL &= ~GPIO_CRL_MODE3_0;
	
	USART2->BRR = 0x009C; //baudrate 115200
	
	USART2->CR1 |= USART_CR1_UE;
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_RE;
	USART2->CR1 |= USART_CR1_RXNEIE;
	
	USART2->CR1 &= ~USART_CR1_M;
	USART2->CR2 &= ~USART_CR2_STOP;
	
	NVIC_EnableIRQ(USART2_IRQn);
}

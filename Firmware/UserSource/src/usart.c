#include "usart.h"

void usart_send(char data)
{
	while(!(USART2->SR & USART_SR_TXE));
	USART2->DR = data;
}

void usart_send_string(char* str)
{
	int i = 0;
	while(str[i])
		usart_send(str[i++]);
}

void usart2_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	GPIOA->CRL &= ~GPIO_CRL_CNF2 | GPIO_CRL_CNF3 | GPIO_CRL_MODE3_0;
	GPIOA->CRL |= GPIO_CRL_CNF2_1 | GPIO_CRL_MODE2_0 | GPIO_CRL_CNF3_0;
	USART2->BRR = 0x009C; // 115200
	USART2->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
	USART2->CR1 &= ~USART_CR1_M;
	USART2->CR2 &= ~USART_CR2_STOP;
	
	NVIC_EnableIRQ(USART2_IRQn);
}

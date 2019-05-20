/* --------------------------------------------------------------------------- */
#include "spi.h"
/* --------------------------------------------------------------------------- */
void spi1_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN;
		
	//SS
	GPIOA->CRL |= GPIO_CRL_MODE4;
	GPIOA->CRL &= ~GPIO_CRL_CNF4;
	GPIOA->BSRR = GPIO_BSRR_BS4;
	
	//SCK
	GPIOA->CRL |= GPIO_CRL_MODE5;
	GPIOA->CRL &= ~GPIO_CRL_CNF5;
	GPIOA->CRL |= GPIO_CRL_CNF5_1;
	
	//MISO
	GPIOA->CRL &= ~GPIO_CRL_MODE6;
	GPIOA->CRL &= ~GPIO_CRL_CNF6;
	GPIOA->CRL |= GPIO_CRL_CNF6_1;
	GPIOA->BSRR |= GPIO_BSRR_BS6;
	
	//MOSI
	GPIOA->CRL |= GPIO_CRL_MODE7;
	GPIOA->CRL &= ~GPIO_CRL_CNF7;
	GPIOA->CRL |= GPIO_CRL_CNF7_1;
	
	SPI1->CR1 = 0x0000;
	SPI1->CR2 = 0x0000;
	SPI1->CR1 |= SPI_CR1_BR; //Baud rate control Fpclk/256
	SPI1->CR1 |= SPI_CR1_CPOL; //Clock polarity CPOL = 0
	SPI1->CR1 |= SPI_CR1_CPHA; //Clock phase CPHA = 0
	SPI1->CR1 &= ~SPI_CR1_DFF; //Data frame format (8-bit data frame format is selected for transmission/reception)
	SPI1->CR1 &= ~SPI_CR1_LSBFIRST; //Frame format (MSB transmitted first)
	SPI1->CR1 |= SPI_CR1_SSM; //Software slave management
	SPI1->CR1 |= SPI_CR1_SSI; //Internal slave select
	SPI1->CR1 |= SPI_CR1_MSTR; //Master mode
	
	SPI1->CR1 |= SPI_CR1_SPE; //Enable SPI1
}

void spi1_write(uint8_t data)
{
	SPI1->DR = data;
	while(!(SPI1->SR & SPI_SR_TXE));
}

uint8_t spi1_read(void)
{
	while(!(SPI1->SR & SPI_SR_RXNE));
	return SPI1->DR;
}

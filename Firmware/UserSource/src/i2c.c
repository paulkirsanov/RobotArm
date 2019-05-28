#include "i2c.h"

void i2c1_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
	
	GPIOB->CRL |= GPIO_CRL_CNF6 | GPIO_CRL_CNF7;
	GPIOB->CRL |= GPIO_CRL_MODE6 | GPIO_CRL_MODE7;
	
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	
	I2C1->CR1 = I2C_CR1_SWRST;
	
	I2C1->CR1 = 0;
	
	I2C1->CR2 &= ~I2C_CR2_FREQ;
  I2C1->CR2 |= 18;   						// Znachenie PCLK1 [MHz]
	I2C1->CCR &= ~I2C_CCR_CCR;
	I2C1->CCR |= 90;							// F = PCLK1/CCR/2
  I2C1->TRISE = 19;							//RISING TIME 1000ns
	
	I2C1->CR1 |= I2C_CR1_PE;
	while((I2C1->CR1 & I2C_CR1_PE) == 0);
}

void i2c2_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
	
	GPIOB->CRH |= GPIO_CRH_CNF10 | GPIO_CRH_CNF11;
	GPIOB->CRH |= GPIO_CRH_MODE10 | GPIO_CRH_MODE11;
	
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
	
	I2C2->CR1 = I2C_CR1_SWRST;
	
	I2C2->CR1 = 0;
	
	I2C2->CR2 &= ~I2C_CR2_FREQ;
  I2C2->CR2 |= 18;   						// PCLK1 [MHz]
	I2C2->CCR &= ~(I2C_CCR_CCR | I2C_CCR_DUTY);
	I2C2->CCR |= 90;							// F = PCLK1/CCR/2
  I2C2->TRISE = 19;							//RISING TIME 1000ns
	
	I2C2->CR1 |= I2C_CR1_PE;
	while((I2C2->CR1 & I2C_CR1_PE) == 0);
}

void i2c_startTransmission(I2C_TypeDef * I2Cx, uint8_t slaveAddress)
{
	while(I2Cx->SR2 & I2C_SR2_BUSY);
	I2Cx->CR1 |= I2C_CR1_START;
	while(!(I2Cx->SR1 & I2C_SR1_SB));
	(void) I2Cx->SR1;
	I2Cx->DR = slaveAddress;
	while(!(I2Cx->SR1 & I2C_SR1_ADDR));
	(void) I2Cx->SR1;
	(void) I2Cx->SR2;
}

void i2c_writeData(I2C_TypeDef * I2Cx, uint8_t data)
{
	while(!(I2Cx->SR1 & I2C_SR1_TXE));
	I2Cx->DR = (uint8_t)data;
	while(!(I2Cx->SR1 & I2C_SR1_BTF));
	
	I2Cx->CR1 |= I2C_CR1_STOP;
}

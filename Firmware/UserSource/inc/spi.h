#ifndef __spi_h
#define __spi_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
/* --------------------------------------------------------------------------- */
#define CS_HIGH()									GPIOA->BSRR |= GPIO_BSRR_BS4;
#define CS_LOW()									GPIOA->BRR |= GPIO_BRR_BR4;

void spi1_init(void);
void spi1_write(uint8_t data);
uint8_t spi1_read(void);
uint8_t spi_write_read(uint8_t data);

#endif

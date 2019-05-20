#ifndef __i2c_h
#define __i2c_h

#include "stm32f10x.h"

void i2c1_init(void);
void i2c2_init(void);
void i2c_startTransmission(I2C_TypeDef * I2Cx, uint8_t slaveAddress);
void i2c_writeData(I2C_TypeDef * I2Cx, uint8_t data);

#endif

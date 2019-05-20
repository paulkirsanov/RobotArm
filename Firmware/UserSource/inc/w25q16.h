#ifndef W25Q16_H
#define W25Q16_H

#include "stm32f10x.h"
#include "spi.h"

#define sFLASH_ID									0xEF4015
#define	sDEVICE_ID								0x14

#define FLASH_Address     				0x00010

#define W25X_WriteEnable		      0x06
#define W25X_WriteDisable		      0x04
#define W25X_ReadStatusReg1		    0x05
#define W25X_ReadStatusReg2		    0x35
#define W25X_WriteStatusReg		    0x01
#define W25X_ReadData			        0x03
#define W25X_FastReadData		      0x0B
#define W25X_FastReadDual		      0x3B
#define W25X_PageProgram		      0x02
#define W25X_BlockErase			      0xD8
#define W25X_SectorErase		      0x20
#define W25X_ChipErase			      0xC7

#define W25X_PowerDown			      0xB9
#define W25X_ReleasePowerDown	    0xAB

#define W25X_DeviceID			        0xAB
#define W25X_ManufactDeviceID   	0x90
#define W25X_JedecDeviceID		    0x9F

#define Dummy_Byte								0xFF
#define W25_PerWritePageSize      256
#define SPI_FLASH_PageSize      	256
#define WIP_Flag                  0x01

uint32_t w25q16_ReadID(void);
uint32_t w25q16_ReadDeviceID(void);
void w25q16_ChipErase(void);
void w25q16_WaitForWriteEnd(void);
void w25q16_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void w25q16_BufferWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void w25q16_BufferRead(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumToRead);
void w25q16_SectorErase(uint32_t SectorAddr);
void w25q16_PowerDown(void);
void w25q16_WakeUp(void);

#endif

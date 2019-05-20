#include "w25q16.h"

uint8_t Tx_Buffer[] = "stm32";
uint8_t Rx_Buffer[5];

uint8_t rx_value;

uint8_t w25q16_spi_send(uint8_t byte)
{
	while(!(SPI1->SR & SPI_SR_TXE));
	SPI1->DR = byte;
	while(!(SPI1->SR & SPI_SR_RXNE));
	return SPI1->DR;
}

uint32_t w25q16_ReadID(void)
{
	uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;
	
	CS_LOW();
	w25q16_spi_send(W25X_JedecDeviceID);
	Temp0 = w25q16_spi_send(Dummy_Byte);
	Temp1 = w25q16_spi_send(Dummy_Byte);
	Temp2 = w25q16_spi_send(Dummy_Byte);
	CS_HIGH();
	
	Temp = ( Temp0 << 16 ) | ( Temp1 << 8 ) | Temp2;
	return Temp;
}

uint32_t w25q16_ReadDeviceID(void)
{
	uint32_t Temp = 0;
	
	CS_LOW();
	w25q16_spi_send(W25X_DeviceID);
	w25q16_spi_send(Dummy_Byte);
	w25q16_spi_send(Dummy_Byte);
	w25q16_spi_send(Dummy_Byte);
	Temp = w25q16_spi_send(Dummy_Byte);
	CS_HIGH();
	
	return Temp;
}

void w25q16_write_enable(void)
{
	CS_LOW();
	w25q16_spi_send(W25X_WriteEnable);
	CS_HIGH();
}

void w25q16_WaitForWriteEnd(void)
{
	uint8_t FLASH_STATUS = 0;
	CS_LOW();
	w25q16_spi_send(W25X_ReadStatusReg1);
	do
	{
		FLASH_STATUS = w25q16_spi_send(Dummy_Byte);
	} while((FLASH_STATUS & WIP_Flag) == SET);
	CS_HIGH();
}

void w25q16_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
	w25q16_write_enable();
	CS_LOW();
	w25q16_spi_send(W25X_PageProgram);
	
	w25q16_spi_send((WriteAddr & 0xFF0000) >> 16);
  w25q16_spi_send((WriteAddr & 0xFF00) >> 8);
  w25q16_spi_send(WriteAddr & 0xFF);
	
	if(NumByteToWrite > W25_PerWritePageSize)
  {
     NumByteToWrite = W25_PerWritePageSize;
  }
  while (NumByteToWrite--)
  {
    w25q16_spi_send(*pBuffer);
    pBuffer++;
  }
	CS_HIGH();
	
	w25q16_WaitForWriteEnd();
}

void w25q16_BufferWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
	uint8_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;
	
	Addr = WriteAddr % SPI_FLASH_PageSize;
  count = SPI_FLASH_PageSize - Addr;
  NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
  NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;
	
	if(Addr == 0)
	{
		if(NumOfPage == 0)
		{
			w25q16_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
		}
		else
		{
			while(NumOfPage--)
			{
				w25q16_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
				WriteAddr += SPI_FLASH_PageSize;
				pBuffer += SPI_FLASH_PageSize;
			}
			
			w25q16_PageWrite(pBuffer, WriteAddr, NumOfSingle);
		}
	}
	else
	{
		if(NumOfPage == 0)
		{
			if(NumOfSingle > count)
			{
				temp = NumOfSingle - count;
				w25q16_PageWrite(pBuffer, WriteAddr, count);
        WriteAddr +=  count;
        pBuffer += count;

        w25q16_PageWrite(pBuffer, WriteAddr, temp);
      }
      else
      {
        w25q16_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
      }
    }
    else /* NumByteToWrite > SPI_FLASH_PageSize */
    {
      NumByteToWrite -= count;
      NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
      NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;

      w25q16_PageWrite(pBuffer, WriteAddr, count);
      WriteAddr +=  count;
      pBuffer += count;

      while (NumOfPage--)
      {
        w25q16_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
        WriteAddr +=  SPI_FLASH_PageSize;
        pBuffer += SPI_FLASH_PageSize;
      }

      if (NumOfSingle != 0)
      {
        w25q16_PageWrite(pBuffer, WriteAddr, NumOfSingle);
      }
    }
  }
}

void w25q16_SectorErase(uint32_t SectorAddr)
{
	w25q16_write_enable();
	w25q16_WaitForWriteEnd();
	CS_LOW();
	w25q16_spi_send(W25X_SectorErase);
	w25q16_spi_send((SectorAddr & 0xFF0000) >> 16);
  w25q16_spi_send((SectorAddr & 0xFF00) >> 8);
  w25q16_spi_send(SectorAddr & 0xFF);
	CS_HIGH();
	w25q16_WaitForWriteEnd();
}

void w25q16_ChipErase(void)
{
	w25q16_write_enable();
	CS_LOW();
	w25q16_spi_send(W25X_ChipErase);
	CS_HIGH();
	w25q16_WaitForWriteEnd();
}

void w25q16_BufferRead(uint8_t *pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
	CS_LOW();
	w25q16_spi_send(W25X_ReadData);
	w25q16_spi_send((ReadAddr & 0xFF0000) >> 16);
  w25q16_spi_send((ReadAddr & 0xFF00) >> 8);
  w25q16_spi_send(ReadAddr & 0xFF);
	
	while(NumByteToRead--)
	{
		*pBuffer = w25q16_spi_send(Dummy_Byte);
		pBuffer++;
	}
	CS_HIGH();
}

void w25q16_PowerDown(void)
{
	CS_LOW();
	w25q16_spi_send(W25X_PowerDown);
	CS_HIGH();
}

void w25q16_WakeUp(void)
{
	CS_LOW();
	w25q16_spi_send(W25X_ReleasePowerDown);
	CS_HIGH();
}

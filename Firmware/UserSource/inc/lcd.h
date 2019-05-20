#ifndef __lcd_h
#define __lcd_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
#include "i2c.h"
/* --------------------------------------------------------------------------- */
#define e_set()				LCD_WriteByteI2CLCD(portlcd |= 0x04)
#define e_reset()			LCD_WriteByteI2CLCD(portlcd &=~ 0x04)
#define rs_set()			LCD_WriteByteI2CLCD(portlcd |= 0x01)
#define rs_reset()		LCD_WriteByteI2CLCD(portlcd &=~ 0x01)
#define setled()			LCD_WriteByteI2CLCD(portlcd |= 0x08)
#define setwrite()		LCD_WriteByteI2CLCD(portlcd &=~ 0x02)
/* --------------------------------------------------------------------------- */
void lcd_init(void);
void LCD_SetPos(uint8_t x, uint8_t y);
void LCD_Clear(void);
void LCD_SendChar(char ch);
void LCD_String(char* st);
void LCD_Dot(uint8_t x, uint8_t y);
/* --------------------------------------------------------------------------- */

void lcd_init(void);

#endif

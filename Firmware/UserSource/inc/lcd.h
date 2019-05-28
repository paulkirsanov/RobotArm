#ifndef __lcd_h
#define __lcd_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
#include "i2c.h"
/* --------------------------------------------------------------------------- */
#define e_set()				lcd_writebytei2clcd(portlcd |= 0x04)
#define e_reset()			lcd_writebytei2clcd(portlcd &=~ 0x04)
#define rs_set()			lcd_writebytei2clcd(portlcd |= 0x01)
#define rs_reset()		lcd_writebytei2clcd(portlcd &=~ 0x01)
#define setled()			lcd_writebytei2clcd(portlcd |= 0x08)
#define setwrite()		lcd_writebytei2clcd(portlcd &=~ 0x02)
/* --------------------------------------------------------------------------- */
void lcd_init(void);
void lcd_setpos(uint8_t x, uint8_t y);
void lcd_clear(void);
void lcd_sendchar(char ch);
void lcd_string(char* st);
void lcd_dot(uint8_t x, uint8_t y);
/* --------------------------------------------------------------------------- */

void lcd_init(void);

#endif

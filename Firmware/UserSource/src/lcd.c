#include "lcd.h"
#include "delay_tim4.h"

uint8_t buf[1] = {0};
char str1[100];
uint8_t portlcd;

void lcd_writebytei2clcd(uint8_t bt)
{
	buf[0] = bt;
	i2c_startTransmission(I2C2, 0x4E);
	i2c_writeData(I2C2, buf[0]);
}

void sendhalfbyte(uint8_t c)
{
	c <<= 4;
	e_set();
	delay_us(50);
	portlcd &= ~0xF0;
	lcd_writebytei2clcd(portlcd |= c);
	e_reset();
	delay_us(50);
}

void sendbyte(uint8_t c, uint8_t mode) 
{
	uint8_t hc = 0;
	if(mode == 0) rs_reset();
	else rs_set();
	hc = c >> 4;
	sendhalfbyte(hc);
	sendhalfbyte(c);
}

void lcd_clear(void)
{
	sendbyte(0x01, 0);
	delay_ms(2);
}

void lcd_sendchar(char ch)
{
	sendbyte(ch, 1);
}

void lcd_string(char* st)
{
	uint8_t i = 0;
	while(st[i] != 0)
	{
		sendbyte(st[i], 1);
		i++;
	}
}

void lcd_setpos(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0:
			sendbyte(x|0x80, 0);
			delay_ms(1);
		break;
		case 1:
			sendbyte((0x40 + x)|0x80, 0);
			delay_ms(1);
			break;
	}
}

void lcd_init(void)
{
	delay_ms(15);
	sendhalfbyte(0x03);
	delay_ms(4);
	sendhalfbyte(0x03);
	delay_us(100);
	sendhalfbyte(0x03);
	delay_ms(1);
	sendhalfbyte(0x02);
	delay_ms(1);
	sendbyte(0x2C, 0); //????? 4 ???, 2 ????? (4 ?????, ????? 5?8)	
	delay_ms(1);
	sendbyte(0x0C, 0);
	delay_ms(1);
	sendbyte(0x06, 0);
	delay_ms(1);
	setled();
	setwrite();
}

void lcd_dot(uint8_t x, uint8_t y)
{
	uint8_t i = 0;
	delay_ms(500);
	for(i = 0; i < 3; i++)
	{
		lcd_setpos(x + i, y);
		lcd_sendchar(0x2E);
		delay_ms(500);
	}
}

#ifndef __usart_h
#define __usart_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
/* --------------------------------------------------------------------------- */

void usart1_init(void);
void usart2_init(void);
void usart_send_string(char* str);
void usart_send(char data);
#endif

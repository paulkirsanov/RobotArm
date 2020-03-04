#ifndef __usart_h
#define __usart_h
/* --------------------------------------------------------------------------- */
#include "stm32f10x.h"
/* --------------------------------------------------------------------------- */

void usart1_init(void);
void usart2_init(void);
void usart_send_string(USART_TypeDef *USART, char* str);
void usart_send_data(USART_TypeDef *USART, char data);
void usartSendArrar(USART_TypeDef *USART, uint8_t *Arrar);

#endif

/*
 * UART.h
 *
 * Created: 26/03/2018 01:25:04 ص
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_
#include "config.h"


volatile unsigned char UART_recv;
void UART_init(void);
unsigned char UART_receive(void);
void UART_send( unsigned char data);
void WriteUART(uint16_t data);
void UART_putstring(char* StringPtr);
ISR(USART_RX_vect);



#endif /* UART_H_ */